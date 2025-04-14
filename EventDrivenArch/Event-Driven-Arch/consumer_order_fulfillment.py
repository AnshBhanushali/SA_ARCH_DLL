import pika
import json
from rabbitmq_config import RABBITMQ_HOST, EXCHANGE_NAME

def handle_fulfillment(ch, method, properties, body):
    order_data = json.loads(body)
    order_id = order_data["order_id"]
    student_name = order_data.get("student_name", "Unknown")

    print(f"[{student_name}] Fulfillment: Order {order_id} fulfilled. Events published.")

    # Open a new connection to send fulfillment confirmation
    conn = pika.BlockingConnection(pika.ConnectionParameters(host=RABBITMQ_HOST))
    chan = conn.channel()

    # Send the 'order-fulfilled' event (used for both internal and notification purposes)
    chan.basic_publish(exchange=EXCHANGE_NAME, routing_key="order-fulfilled", body=json.dumps(order_data))
    chan.basic_publish(exchange=EXCHANGE_NAME, routing_key="order-fulfilled", body=json.dumps(order_data))

    conn.close()

# Set up consumer to listen for 'payment-applied' events
conn = pika.BlockingConnection(pika.ConnectionParameters(host=RABBITMQ_HOST))
chan = conn.channel()
chan.queue_declare(queue="fulfillment_queue")
chan.queue_bind(exchange=EXCHANGE_NAME, queue="fulfillment_queue", routing_key="payment-applied")

chan.basic_consume(queue="fulfillment_queue", on_message_callback=handle_fulfillment, auto_ack=True)

print("Waiting for fulfillment messages...")
chan.start_consuming()

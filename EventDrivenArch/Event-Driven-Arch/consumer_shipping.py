import pika
import json
from rabbitmq_config import RABBITMQ_HOST, EXCHANGE_NAME

def handle_shipping(ch, method, properties, body):
    order_data = json.loads(body)
    order_id = order_data["order_id"]
    student_name = order_data.get("student_name", "Unknown")

    print(f"[{student_name}] Shipping: Order {order_id} shipped. Events published.")

    # Send out the shipping notification
    conn = pika.BlockingConnection(pika.ConnectionParameters(host=RABBITMQ_HOST))
    chan = conn.channel()

    chan.basic_publish(
        exchange=EXCHANGE_NAME,
        routing_key="order-shipped",
        body=json.dumps(order_data)
    )

    conn.close()

# Setup the consumer to listen for fulfilled orders
conn = pika.BlockingConnection(pika.ConnectionParameters(host=RABBITMQ_HOST))
chan = conn.channel()
chan.queue_declare(queue="shipping_queue")
chan.queue_bind(exchange=EXCHANGE_NAME, queue="shipping_queue", routing_key="order-fulfilled")

chan.basic_consume(queue="shipping_queue", on_message_callback=handle_shipping, auto_ack=True)

print("Waiting for shipping messages...")
chan.start_consuming()

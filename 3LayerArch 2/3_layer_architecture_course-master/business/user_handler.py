from business.model.user import User
from business.user_service import UserService


class UserHandler:

    def __init__(self):
        self.user_service = UserService()

    def create_user(self, incoming_data):
        user = User(
            incoming_data.get('user_name', None),
            incoming_data.get('first_name', None),
            incoming_data.get('last_name', None)
        )
        user_id = self.user_service.create(user)
        user.user_id = user_id
        return user.__dict__

    def get_user(self, user_id):
        user_id_int = fault_safe_to_int(user_id)
        user = self.user_service.get(user_id_int)
        return user.__dict__

    # New method for retrieving all users
    def get_all_users(self):
        users = self.user_service.get_all_users()
        return [user.__dict__ for user in users]

def fault_safe_to_int(user_id):
    try:
        return int(user_id)
    except:
        return None

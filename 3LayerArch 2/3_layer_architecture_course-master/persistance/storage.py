from business.model.user import User

class UserStorage:

    def add(self, user: User) -> int:
        raise NotImplementedError()

    def get(self, user_id: int) -> User:
        raise NotImplementedError()
    
    def delete(self, user_id: int):
        raise NotImplementedError()
    
    def update(self, user: User):
        raise NotImplementedError()

    def find_by_user_name(self, user_name: str) -> User:
        raise NotImplementedError()
    
    # New method for retrieving all users
    def get_all_users(self) -> list:
        raise NotImplementedError()

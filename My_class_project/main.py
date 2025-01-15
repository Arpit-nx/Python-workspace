class user:
    #pass #This keyword aloows u to move ahead any function or class without any problem...
    def __init__(self, user_id, username):
        self.id = user_id
        self.username = username
        self.followers = 0
        self.following = 0

    def follow(self, user):
        user.followers += 1
        self.following += 1

user_1 = user("203", "ARPIT")
user_2 = user("204", "ANKIT")

print(user_1.id)

user_1.follow(user_2)
user_2.follow(user_1)

print(user_1.following)
print(user_1.followers)
print(user_2.following)
print(user_2.followers)


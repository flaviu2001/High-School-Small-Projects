import praw
import config
import time
import os

comments_replied_to = []

def get_comment_list():
    global comments_replied_to
    if not os.path.isfile("comment_list.txt"):
        open("comment_list.txt", "w+")
    with open("comment_list.txt", "r") as f:
        comments_replied_to = f.read()
        comments_replied_to = comments_replied_to.split("\n")
    comments_replied_to = filter(None, comments_replied_to)

def login():
    print("logging in")
    r = praw.Reddit(username=config.username,
                password=config.password,
                client_id=config.client_id,
                client_secret=config.client_secret,
                user_agent="Take your upvote bot thing guy");
    print("logged in")
    return r

def run(r):
    print("obtaining comments...")
    found = False
    for comment in r.subreddit('all').comments(limit = 100):
        if 'take your upvote and leave' == comment.body and comment.id not in comments_replied_to:
            print("got one")
            found = True
            comment.reply(config.message)
            comments_replied_to.append(comment.id)
            with open("comment_list.txt", "a") as f:
                f.write(comment.id + "\n")
    if not found:
        print("No new matching comments")

get_comment_list()
r = login()
while(True):
    run(r)
    time.sleep(10)

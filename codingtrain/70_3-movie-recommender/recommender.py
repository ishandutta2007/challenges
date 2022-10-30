#!/usr/bin/env python

import argparse
import json
import math

def load_json(name):
    file = open(name)
    data = json.load(file)
    file.close()
    return data

def similarity(titles, ratings1, ratings2):
    value = 0
    for title in titles:
        try:
            value += (ratings1[title] - ratings2[title])**2
        except:
            pass
    return 1 / (1 + math.sqrt(value))

def recommend(database, user, kth):
    users = database["users"]
    titles = database["titles"]

    neighbors = []
    for xuser in users:
        result = type('', (object,), {"score": 0, "ratings": None})()
        result.ratings = xuser
        result.score = similarity(titles, user, xuser)
        neighbors.append(result)
    neighbors.sort(key=lambda x: x.score, reverse=True)

    for title in titles:
        if user.get(title) != None:
            continue

        weighted = 0
        similar = 0
        for i in range(kth):
            neighbor = neighbors[i]
            rating = neighbor.ratings.get(title)
            if rating != None:
                weighted += neighbor.score * rating
                similar += neighbor.score
        
        print("%s: %.2f" % (title, weighted/similar))

def main():
    parser = argparse.ArgumentParser(description='Movies Recommender')
    parser.add_argument('user', metavar='', type=str, nargs='?', help='user ratings file')
    parser.add_argument("--neighbors", type=int, default=5, help='specify kth nearest neighbors to look at')
    parser.add_argument("--database", type=str, default='movies.json', help='database file')
    args = parser.parse_args()

    if args.user == None:
        parser.print_help()
        parser.exit()

    database = load_json(args.database)
    user = load_json(args.user)
    recommend(database, user, args.neighbors)

main()

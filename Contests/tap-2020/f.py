def print_solution(points, games, last_winner):
    if not last_winner:
        print(f'{games[0]} ({points[0]}*) - {games[1]} ({points[1]})')
    else:
        print(f'{games[0]} ({points[0]}) - {games[1]} ({points[1]}*)')

def is_game_ended(games):
    return games[0] >= 2 or games[1] >= 2

def get_last_winner(last_winner):
    return 1 if last_winner else 0

def check_end_game(points, last_winner):
    return (points[get_last_winner(last_winner)] >= 5 and abs(points[0] - points[1]) >= 2) or points[get_last_winner(last_winner)] >= 10

def print_last_solution(games):
    if is_game_ended:
        if games[0] >= games[1]:
            print(f'{games[0]} (winner) - {games[1]}')
        else:
            print(f'{games[0]} - {games[1]} (winner)')
    else:
        print(f'{games[0]} - {games[1]}')

match = [char for char in input()]  

points = [0, 0]
games = [0, 0]
char = match[0]
first = 0

if char == 'Q':
   print_solution(points, games, None) 
   char = match[1]
   first = 1

char = match[first]
last_winner = char != 'S'
points[get_last_winner(last_winner)] += 1

for i in range(first + 1, len(match)):
    char = match[i]

    if char != 'Q' and not is_game_ended(games):
        if char == 'R':
            last_winner = not last_winner
        points[get_last_winner(last_winner)] += 1

        if check_end_game(points, last_winner):
            points = [0, 0]
            games[get_last_winner(last_winner)] += 1
    else:
        if char == 'Q':
            if i < len(match) and not is_game_ended(games):
                print_solution(points, games, last_winner)
            else:
                print_last_solution(games)


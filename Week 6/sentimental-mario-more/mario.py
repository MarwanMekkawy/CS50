# endless loop breaks with condition
while True:
    Height = input("insert Height: ")
    # if not a number skip this itration and start new one
    if not Height.isdigit():
        continue
    Height = int(Height)
    # if number check between 1-8 if right escape the loop
    if Height > 0 and Height < 9:
        break
# print the bricks
for i in range(Height):
    print(" "*(Height-(i+1)), "#"*(i+1), "  ", "#"*(i+1), sep="")

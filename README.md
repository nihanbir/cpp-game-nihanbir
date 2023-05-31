[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/xhZBU6iz)

# Klicker

Simple clicker game made for a school assignment, left clicking the door to open/close it and right click to leave the room.

The game is made with SDL using; 

## Design Patterns

### - State design pattern 

    - Each door is independent of each other and has 2 states, open and closed. This pattern helps make the game scalable if you want to increase the complexity. (eg. LockedDoorState)

### - Update design pattern

    - Since every door is independent of each other, it makes sense for each door to update their own state instead of listing all the updates in the main loop. This pattern also helps making the game scalable.

## Advanced C++ Features
### - Vectors 

    - For scalable collection of the doors.

    - It solves the problem of making it easier to scale the amount of functional doors in the future.

### - Runtime polymorphism 

    - To change the state of the doors.

    - Required by the state design pattern.

![Screenshot 2023-04-16 164041](https://user-images.githubusercontent.com/112477158/232321346-fe2c131d-9f93-477e-988e-169d7bf66960.png)

![Screenshot 2023-04-16 164115](https://user-images.githubusercontent.com/112477158/232321350-95d7112c-f33b-436b-a4e2-6f1c7fd4c449.png)

![Untitled video - Made with Clipchamp (6)](https://user-images.githubusercontent.com/112477158/232321356-97aa747b-8f79-432d-9434-2f6d56157326.gif)

<sup>Video depicts an earlier version of the game</sup>

# Street_View_Routing_Google_Hash-Code_2014

## Introduction 
Google Strret View Cars capture imagery by driving through city streets. The Challenge is to plan routes for a fleet of these cars to maximize on time and the number of Cars.

## Task
Need To schedule the movment to the cars to ensure they cover the maximim length to streets within the given time limit. Each street should be traversed atv least once to be counted towards the total score.

## Proble Description
    - City Representation
         1. The City is Modeled as a graph:
            - Nodes represent city juntions.
            - Edges represent street connecting these junctions.

         2. Each edge has the following properties:
            - Direction:- Either one-directional or bi-directional.
            - Length:- the distance covered by the street view car.
            - cost:- The time taken to traverse the street.

## Input Data
The input data provided in a plain text file with following structure.

1. First Line:
   
         - 'N' Number of junctions
         - 'M' Number of streets.
         - 'T' Virtual time in seconds allowed for the cars itieraries.
         - 'C' Number of cars in the fleet.
         - 'S' The starting journy of all cars.

2. Next N Lines: Each line contains the geographical coordinates (latitude and longitude) of a junction.
3. Next M Lines: Each line describes a street with:
   
- Aj, Bj: Indices of the junctions connected by the street.
- Dj: Direction of the street (1 for one-directional, 2 for bi-directional).
- Cj: Time cost to traverse the street.
- Lj: Length of the street.

## Example Input

- 3 2 3000 2 0
- 48.8582   2.2945
- 50.0  3.00
- 51.424242    3.02 
- 0 1 1 30    250
- 1 2 2 45   200

## This means:

-3 junctions, 2 streets, 3000 seconds allowed, 2 cars, starting at junction 0.
-Junction coordinates are given.
-Street details follow.

## Movement of Cars

- Cars start at the specified junction S.
- The itinerary for each car must fit within the given virtual time T.
- Traversing a street more than once or in both directions (if bi-directional) does not increase the score.

## Output Data
Your solution must be described in a plain text file with:

- A single natural number indicating the number of cars.
- For each car, the number of junctions visited followed by the list of junctions in the order they were visited.

## Example Of Output

- 2
- 1
- 0
- 3
- 0
- 1
- 2

## This means:

- 2 cars.
- First car stays at junction 0.
- Second car visits junctions 0, 1, and 2.

















  

//
//  recursion.cpp
//  Homework 2
//
//  Created by Ava Gonick on 7/25/23.
//
#include <cassert>
#include <iostream>
#include <string>

using namespace std;


//Question 1
//part 1


// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int productOfTheSystem(unsigned int m, unsigned int n)
{
    if( n == 0){ //if n equals 0 return because have added enough times
        return 0;
    }
    int add = productOfTheSystem(m, n-1); //returns m added n-1 times
    return add + m; //adds m another time
}

//part 2
// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
int accountForADigit(int num, int digit)
{
    if(num == 0)
        return 0;
    //goes by dividing by 10 because this is an int so the decimal point will be lost and will get rid of the last number in the intger
   int numdig = accountForADigit(num / 10, digit);
    
    //if the last digit in the number is the digit we are looking for increment numdig
    if(num % 10 == digit)
        numdig++;
    return numdig;
}

//part 3

// Returns a string where the same characters next each other in
// string n are separated by "88" (you can assume the input
// string will not have 8’s)

string eightClap(string n){
    if(n == "")
        return "";
    if(n.size() == 1)
        return n;
    string clap = eightClap(n.substr(0, n.size() -1));
    
    //if same character before add the 88 then the character
    if (n[n.size() - 1] == clap[clap.size()-1] ){
        clap += "88";
        clap += n[n.size() -1];
    }
    else
        //if different character before add on charcter to clap
        clap += n[n.size() -1];
    return clap;
        
}

//part 4

// str contains a single pair of the less than and greater than
// signs, return a new string made of only the less than and
// greater than sign and whatever is contained in between
string coneHeads(string str)
{
    if(str[str.size() -1] == '<')
        return "<";
    
    //this does recursion starting at the at the front of string to back (though it stops at front with the first '<'
    string newstr = coneHeads(str.substr(0, str.size() - 1));
    
    //if dont already have the closing brackets in the newstring add on values
    if(newstr[newstr.size() -1] != '>'){
        newstr += str[str.size()-1];
        return newstr;
    }
    
    //just return self if don't add
    else
        return newstr;
}
// part 5
    // Return true if the total of any combination of elements in
    // the array a equals the value of the target.
    bool conglomerateOfNumbers(const int a[], int size, int target)
    {
        
        //if target gets to 0 subtracted enough out that it does add up
        if(target == 0)
            return true;
        
        //if size = 0 means iterated through everything and didn't add up
        if( size == 0)
            return false;
        
        bool include = conglomerateOfNumbers(a, size - 1, target); //if include this value will it equal target
        
        //since including this number need to subtract it out (if negative will add to it and this is also ok)
        target -= a[size - 1];
        
    
        bool exclude = conglomerateOfNumbers(a, size -1, target); //if exclude this value will it equal
        //sinze excluding this number don't need to include it
        
        if(include == true || exclude == true)
            return true;
        else
            return false;
        
    }
    
    
//question 2

bool findAWay(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec){
    
    //if the start location is equal to the ending location then we've solved the maze so return true
    if(sr == er && sc == ec)
        return true;
    
    //mark the start location as visited
    maze[sr].at(sc) = '#';
    
    //check to the left if unvisited and open
    if(maze[sr-1].at(sc) == '.')
        if(findAWay(maze, nRows, nCols, sr - 1, sc, er, ec))
            return true;
    
    //check to the right if unvisited and open
    if(maze[sr+1].at(sc) == '.')
        if(findAWay(maze, nRows, nCols, sr + 1, sc, er, ec))
            return true;
    
    //check if down is unvisited and open
    if(maze[sr].at(sc-1) == '.')
        if(findAWay(maze, nRows, nCols, sr, sc - 1, er, ec))
            return true;
    
    //check if up is unvisited and open
    if(maze[sr].at(sc+1) == '.')
        if(findAWay(maze, nRows, nCols, sr, sc + 1, er, ec))
            return true;
    
    //if reach here then couldn't find any ways
    return false;
}
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwis
//so can only go through . the walkway
//make sure to drop a crumn and change things to something so that know it has been visited
//maze is an array of strings, so the columns are each string and the columns are different strings
//sr starting row sc starting columns, will be given in range
//end will be er and ec and are also in range
//only can move up down left right
//maze can be modified
//(0,0) is upper left and as go south increase number and as go right increase number


int main(){
 /*   //testing
   
    //test n = 1
    //test m = 1
    //test m = 2
    //test n = 2
    
    //test m = 0
    //test n = 0
    assert( productOfTheSystem(0 , 0)  == 0);
    
    //test m = 0
    //test n = 1
    assert( productOfTheSystem(0 , 1) == 0);
    
    //test m = 1
    //test n = 0
    assert( productOfTheSystem(1 , 0) == 0);
    
    //test m = 2
    //test n = 2
    assert( productOfTheSystem(2 , 2) == 4);
    
    //test m = 0
    //test n = 2
    assert( productOfTheSystem(0 , 2) == 0);
    
    //test m = 5
    //test n = 2
    
    assert(productOfTheSystem(5 , 2) == 10);
    
    
    //acountForADigit
    //test a 0
    assert(accountForADigit(0, 0)  == 0);
    //test a long string with the number
    //test 18838 with 8
    assert(accountForADigit(18838, 8) == 3);
    
    //test a long string without the number
    //test 55555 with a 3
    
    assert(accountForADigit(55555, 3) == 0);
    
    
    //check it can catch a string of zeros
    assert(accountForADigit(100000, 0) == 5);
    
    //test eightclap
    //test empty string
    assert(eightClap("") == "");
    
    //test two in a row in middle
    assert(eightClap("goodbye") == "go88odbye");
    
    //test string one character
    assert(eightClap("m") == "m");
    
    //test 4 in a row the same
    assert(eightClap("aaaa") == "a88a88a88a");
    
    //test 2 in a row the same but multiple
    assert(eightClap("yyuu") == "y88yu88u");
    
    //test coneHead
    
    //test the < > in the middle
    assert(coneHeads("abc<ghj>789") == "<ghj>");
    
    //test only one character in the middle of the <>
    assert(coneHeads("<x>7") == "<x>");
    
    //test the < > with the character at the end
    assert(coneHeads("4agh<y>") == "<y>");
    
    //test most a <> in solutino
    assert(coneHeads("4agh<>") == "<>");
    
    //test basic case of just a <>
    assert(coneHeads("<>") ==  "<>");
    
    //test conglomerate of numbers
    
    int check[3] = {2, 4, 8};
    int empty[0];
    
    //check if add numbers not in order it works
    assert(conglomerateOfNumbers(check, 3, 10));
    
    //check if add any two numbers it works
    assert(conglomerateOfNumbers(check, 3, 6));
    
    //check it works when number not found
    assert(!conglomerateOfNumbers(check, 3, 11));
    
    //check it works if equal 0 (should always be true because add non equals 0)
    assert(conglomerateOfNumbers(check, 3, 0));
    
    //check it works with empty array
    assert(conglomerateOfNumbers(empty, 0, 0));
    
    //check if add everything it works
    assert(conglomerateOfNumbers(check, 3, 14));
    
    //check if positive array and negative target it returns false
    
    assert(!conglomerateOfNumbers(check, 3, -4));
    
    //check if it works with array size one
    
    int sizeone[1] = {3};
    //check size1 and it is the correct number it works
    assert(conglomerateOfNumbers(sizeone, 1, 3));
    
    //check size1 and not correct number it works
    
    assert(!conglomerateOfNumbers(sizeone, 1, 5));
    
    //check array with negative numbers
    
    int negnum[10] = {-1, -6, -4, 6, 5, -10, -15, 3, 2, 33};
    
    //check array with negative numbers can go to a negative target
    
    assert(conglomerateOfNumbers(negnum, 10, -7));
    
    //check array with negative numbers with positive target
    
    assert(!conglomerateOfNumbers(negnum, 10, 50));
    
    //check question 2 the maze
    
    //check a regular maze
    string maze[10] = {
    "XXXXXXXXXX",
    "X.......@X",
    "XX@X@@.XXX",
    "X..X.X...X",
    "X..X...@.X",
    "X....XXX.X",
    "X@X....XXX",
    "X..XX.XX.X",
    "X...X....X",
    "XXXXXXXXXX"
    };
    assert(findAWay (maze, 10, 10, 6, 4, 1, 1));

    //check maze where starting point and ending point are the same
    
    assert(findAWay(maze, 10, 10, 1, 4, 1, 4));
    
    string maze2[5] =
    {"XXXXXXX",
    "X...X@X",
    "XXX.X.X",
    "X@....X",
    "XXXXXXX"};
    
    //check again something with a solution
    
    assert(findAWay( maze2, 10, 10, 3, 3, 1, 2));
    
    
    string maze3[7]=
    {
        "XXXXXX",
        "X...@X",
        "X@@..X",
        "XXXXXX",
        "X..@.X",
        "X...X.",
        "XXXXXX"
        
    };
    
    //check something with no solution
    assert(!findAWay(maze3,7, 6, 1, 2, 5, 3 ));
    
    //check something just one open space is the answer
    
    string maze4[3]=
    {
        "XXX",
        "X.X",
        "XXX"
    };
    
    assert(findAWay(maze4, 3, 3, 1, 1, 1, 1));
    
    cout << "all done";
  */
    return 0;
    
}

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <string>


using namespace std;
/*
 * 
 */

void initializeBoard(map<pair<char, int>, char> &m);
void placeOpponentShip(map<pair<char,int>,char> &m, int num, char shipType, bool shipDirection);
void opponentShipsPlaced(map<pair<char,int>,char> &m);
void yourShipsPlaced(map<pair<char,int>,char> &m);
bool placeYourShip(map<pair<char,int>,char> &m, int num, char shipType, int shipDirection, char x, int y);
int randomm(int min, int max);
void enterToCont();

int main(int argc, char** argv) {
    
    srand(time(0));
    
    
    cout << "Welcome to battleship." << endl;
    void enterToCont();
    cout << "Rules" << endl;
    cout << "Players will place 5 ships or varying sizes on the board and take turns picking points to try eliminating their opponent's ships." << endl;
    cout << "The first player to eliminate all their opponent's ships wins." << endl;
    void enterToCont();
    
    const int BOARD_SIZE = 10;
    
    //creating the boards
    map <pair<char, int>, char> yourBoard;
    map <pair<char, int>, char> opponentBoard;
      
    initializeBoard(yourBoard);
    initializeBoard(opponentBoard);
    
    
    
    
    
    list<char> yourShips{'C', 'B', 'R', 'S', 'D'};
    list<char> opponentShips{'C', 'B', 'R', 'S', 'D'};
   
    
    opponentShipsPlaced(opponentBoard);
    
    yourShipsPlaced(yourBoard);
    
    return 0;
}

void initializeBoard(map<pair<char, int>, char> &m)
{
    for(char x = 65; x < 75; x++)
    {
        for(int y = 1; y <= 10; y++)
        {
            m[{x,y}] = 'W'; 
        }
    }
}
void placeOpponentShip(map<pair<char,int>,char> &m, int num, char shipType, int shipDirection)
{
    bool noShip = true;
    do
    {
        noShip = true;
        
        //Choosing starting coordinate
        char x = randomm(65, 74);
        int y = randomm(0,10);
        if(shipDirection == 1) //Ship is horizontal
        {
            if (x + num - 1 > 74)
            {
            noShip = false;
            }
            for(int i = 0; i < num; i++)
            {
                //Checks if there is a ship there
                //
                if(m[{x + i,y}] == 'W')
                {}
                else
                {
                    noShip = false;
                }
            }
            if (noShip == true)
            {
                for(int i = 0; i < num; i++)
                {
                    m[{x+i,y}] = shipType;
                }
            }
        }
        else
        {
            if (y + num - 1 > 9)
            {
            noShip = false;
            }
            
            for(int i = 0; i < num; i++)
            {
                //Checks if there is a ship there
                //
                if(m[{x,y+i}] == 'W')
                {}
                else
                {
                    noShip = false;
                }
            }
            if (noShip == true)
            {
                for(int i = 0; i < num; i++)
                {
                    m[{x,y+i}] = shipType;
                }
            }
        }
    }while(noShip == false);
    

}
void opponentShipsPlaced(map<pair<char,int>,char> &m)
{
    //Placing Carrier (5 Units)
    int shipDirection = randomm(0,1);
    placeOpponentShip(m, 5, 'C', shipDirection); //Carrier
    shipDirection = randomm(0,1);
    placeOpponentShip(m, 4, 'B', shipDirection); //Battleship
    shipDirection = randomm(0,1);
    placeOpponentShip(m, 3, 'R', shipDirection); //Cruiser
    shipDirection = randomm(0,1);
    placeOpponentShip(m, 3, 'S', shipDirection); //Submarine
    shipDirection = randomm(0,1);
    placeOpponentShip(m, 2, 'D', shipDirection); //Destroyer
    
}
void yourShipsPlaced(map<pair<char,int>,char> &m)
{
    int shipDirection;
    char x;
    int y;
    
    cout << "You will now place your ships" << endl;
    cout << "If you try to place a ship in a taken spot, you will be asked to place your ship again" << endl;
    
    cout << "You have placed no ships yet" << endl;
    cout << "Placing Carrier" << endl;
    
    do
    {
        cout << "Would you like your Carrier to be horizontal or vertical?" << endl;
        cout << "Enter [0] for vertical or [1] for horizontal. "; 
        cin >> shipDirection;
        
        if(shipDirection == 0 || shipDirection == 1)
        {
            cout << "Select the starting point for your ship." << endl;
            cout << "Carrier is five units long. Ensure that your ship will fit within the 10x10 board." << endl;
            cout << "Enter the letter value. For example, if you wish to start at A1, enter A: ";
            cin >> x;
            cout<< "Enter the numerical value. For example, if you wish to start at A1, enter 1: ";
            cin >> y;
            if(placeYourShip(m, 5, 'C', shipDirection, x, y))
            {
                cout << "Carrier has been placed in the following spaces: " << endl;
                if (shipDirection == 1) // horizontal
                {
                    for (int i = 0; i < 5; i++)
                    {
                        cout << (char)(x + i) << y << endl;
                    }
                }
                else
                {
                    for (int i = 0; i < 5; i++)
                    {
                        cout << x << y + i << endl;
                    }
                }
            }
            else
            {
                cout << "Your ship has crashed into another ship or has fallen off the board." << endl;
                cout << "Try placing your ship somewhere else." << endl;
                shipDirection = -1;
            }
        }
        else
        {
            cout << "Invalid Input. Please try again.";
        }
    }while(shipDirection != 0 && shipDirection != 1);
    
    cout << "You have placed 1 ship." << endl;
    cout << "Placing Battleship" << endl;
    
    do
    {
        cout << "Would you like your Battleship to be horizontal or vertical?" << endl;
        cout << "Enter [0] for vertical or [1] for horizontal. "; 
        cin >> shipDirection;
        
        if(shipDirection == 0 || shipDirection == 1)
        {
            cout << "Select the starting point for your ship." << endl;
            cout << "Battleship is 4 units long. Ensure that your ship will fit within the 10x10 board." << endl;
            cout << "Enter the letter value. For example, if you wish to start at A1, enter A: ";
            cin >> x;
            cout<< "Enter the numerical value. For example, if you wish to start at A1, enter 1: ";
            cin >> y;
            if(placeYourShip(m, 4, 'B', shipDirection, x, y))
            {
                cout << "Battleship has been placed in the following spaces: " << endl;
                if (shipDirection == 1) // horizontal
                {
                    for (int i = 0; i < 4; i++)
                    {
                        cout << (char)(x + i) << y << endl;
                    }
                }
                else
                {
                    for (int i = 0; i < 4; i++)
                    {
                        cout << x << y + i << endl;
                    }
                }
            }
            else
            {
                cout << "Your ship has crashed into another ship or has fallen off the board." << endl;
                cout << "Try placing your ship somewhere else." << endl;
                shipDirection = -1;
            }
        }
        else
        {
            cout << "Invalid Input. Please try again.";
        }
    }while(shipDirection != 0 && shipDirection != 1);
    
    cout << "You have placed 2 ships." << endl;
    cout << "Placing Cruiser" << endl;
    
    do
    {
        cout << "Would you like your Cruiser to be horizontal or vertical?" << endl;
        cout << "Enter [0] for vertical or [1] for horizontal. "; 
        cin >> shipDirection;
        
        if(shipDirection == 0 || shipDirection == 1)
        {
            cout << "Select the starting point for your ship." << endl;
            cout << "Cruiser is 3 units long. Ensure that your ship will fit within the 10x10 board." << endl;
            cout << "Enter the letter value. For example, if you wish to start at A1, enter A: ";
            cin >> x;
            cout<< "Enter the numerical value. For example, if you wish to start at A1, enter 1: ";
            cin >> y;
            if(placeYourShip(m, 3, 'R', shipDirection, x, y))
            {
                cout << "Cruiser has been placed in the following spaces: " << endl;
                if (shipDirection == 1) // horizontal
                {
                    for (int i = 0; i < 3; i++)
                    {
                        cout << (char)(x + i) << y << endl;
                    }
                }
                else
                {
                    for (int i = 0; i < 3; i++)
                    {
                        cout << x << y + i << endl;
                    }
                }
            }
            else
            {
                cout << "Your ship has crashed into another ship or has fallen off the board." << endl;
                cout << "Try placing your ship somewhere else." << endl;
                shipDirection = -1;
            }
        }
        else
        {
            cout << "Invalid Input. Please try again.";
        }
    }while(shipDirection != 0 && shipDirection != 1);
    
    cout << "You have placed 3 ships." << endl;
    cout << "Placing Submarine." << endl;
    
    do
    {
        cout << "Would you like your Submarine to be horizontal or vertical?" << endl;
        cout << "Enter [0] for vertical or [1] for horizontal. "; 
        cin >> shipDirection;
        
        if(shipDirection == 0 || shipDirection == 1)
        {
            cout << "Select the starting point for your ship." << endl;
            cout << "Submarine is 3 units long. Ensure that your ship will fit within the 10x10 board." << endl;
            cout << "Enter the letter value. For example, if you wish to start at A1, enter A: ";
            cin >> x;
            cout<< "Enter the numerical value. For example, if you wish to start at A1, enter 1: ";
            cin >> y;
            if(placeYourShip(m, 3, 'S', shipDirection, x, y))
            {
                cout << "Submarine has been placed in the following spaces: " << endl;
                if (shipDirection == 1) // horizontal
                {
                    for (int i = 0; i < 3; i++)
                    {
                        cout << (char)(x + i) << y << endl;
                    }
                }
                else
                {
                    for (int i = 0; i < 3; i++)
                    {
                        cout << x << y + i << endl;
                    }
                }
            }
            else
            {
                cout << "Your ship has crashed into another ship or has fallen off the board." << endl;
                cout << "Try placing your ship somewhere else." << endl;
                shipDirection = -1;
            }
        }
        else
        {
            cout << "Invalid Input. Please try again.";
        }
    }while(shipDirection != 0 && shipDirection != 1);
    
    cout << "You have placed 4 ships." << endl;
    cout << "Placing last ship, Destroyer." << endl;
    
    do
    {
        cout << "Would you like your Destroyer to be horizontal or vertical?" << endl;
        cout << "Enter [0] for vertical or [1] for horizontal. "; 
        cin >> shipDirection;
        
        if(shipDirection == 0 || shipDirection == 1)
        {
            cout << "Select the starting point for your ship." << endl;
            cout << "Destroyer is 2 units long. Ensure that your ship will fit within the 10x10 board." << endl;
            cout << "Enter the letter value. For example, if you wish to start at A1, enter A: ";
            cin >> x;
            cout<< "Enter the numerical value. For example, if you wish to start at A1, enter 1: ";
            cin >> y;
            if(placeYourShip(m, 2, 'D', shipDirection, x, y))
            {
                cout << "Destroyer has been placed in the following spaces: " << endl;
                if (shipDirection == 1) // horizontal
                {
                    for (int i = 0; i < 2; i++)
                    {
                        cout << (char)(x + i) << y << endl;
                    }
                }
                else
                {
                    for (int i = 0; i < 2; i++)
                    {
                        cout << x << y + i << endl;
                    }
                }
            }
            else
            {
                cout << "Your ship has crashed into another ship or has fallen off the board." << endl;
                cout << "Try placing your ship somewhere else." << endl;
                shipDirection = -1;
            }
        }
        else
        {
            cout << "Invalid Input. Please try again.";
        }
    }while(shipDirection != 0 && shipDirection != 1);
    
    cout << "You have placed all your ships." << endl;
    
}
bool placeYourShip(map<pair<char,int>,char> &m, int num, char shipType, int shipDirection, char x, int y)
{
    bool noShip = true;
        if(shipDirection == 1) //Ship is horizontal
        {
            for(int i = 0; i < num; i++)
            {
                //Checks if there is a ship there
                //
                if(m[{x+i,y}] == 'W')
                {}
                else
                {
                    noShip = false;
                }
            }
            if (noShip == true)
            {
                for(int i = 0; i < num; i++)
                {
                    m[{x+i,y}] = shipType;
                }
            }
        }
        else
        {
            //Choosing starting coordinate
            for(int i = 0; i < num; i++)
            {
                //Checks if there is a ship there
                //
                if(m[{x,y+i}] == 'W')
                {}
                else
                {
                    noShip = false;
                }
            }
            if (noShip == true)
            {
                for(int i = 0; i < num; i++)
                {
                    m[{x,y+i}] = shipType;
                }
            }
        }
    return noShip;
}
int randomm(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
void enterToCont()
{
    string enter;
    cout << "Press enter to continue";
    cin >> enter;
}
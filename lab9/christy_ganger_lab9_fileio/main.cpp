#include <iostream>
#include <iomanip> // for shapes
#include <fstream> // file stream

using namespace std;
void drawRect(char out_char, int rows, int columns);
void draw_triangle(char out_char, int rows, int columns);
void draw_square(char out_char, int rows, int columns);
void draw_diamond(char out_char, int rows, int columns);
bool playagain();
int main()
{
    do
    {
        int rows = 0, columns =0;
        char value;
// doing file stream
        ifstream inFile;
        inFile.open("hello.txt");

        int num;
// first case
        cout << "loading first run to end of file listing numbers" << "\n";
        while (!(inFile.eof()))
        {
            inFile >> num;
            cout << num << "\n";
        }
        inFile.close();

// second case
        cout << "loading numbers directly num in while loop" << "\n";
        inFile.open("hello.txt");
        while (inFile >> num)
        {
            cout << num << "\n";
        }
        inFile.close();

// third case
        cout << "adding all" << "\n";
        inFile.open("hello.txt");
        int total = 0;
        while(inFile >> num)
        {
            total += num;
        }
        inFile.close();
        cout << total << "\n";

// fourth case
        cout << "doing the average" << "\n";
        inFile.open("hello.txt");
        total = 0;
        int counter = 0;
        while (inFile >> num)
        {
            total += num;
            counter++;
        }
        double average = static_cast<double>(total)/counter;
        cout << average << "\n";

// end file stream stuff test and learn

        cout << "Enter your character, row and column values" << endl;
        cin >> value >> rows >> columns;
        drawRect(value,rows,columns);
        draw_triangle(value,rows,columns);
        draw_square(value,rows,columns);
        draw_diamond(value,rows,columns);

    }while(playagain());
    return 0;
}

/*here you would have code that outputs a shape using out_char for example,
drawRect(&,3,2)
  &&
  &&
  &&
  */
void drawRect(char out_char, int rows, int columns)
{
    for (int counter = 1; counter <= columns; counter++)
    {


        for (int counter = 1; counter <=rows; counter++)
        {
            cout << out_char;
        }
        cout << "\n";

    }
cout << "\n\n\n";
return;
}

void draw_triangle(char out_char, int rows, int columns)
{

    int out_counter = 0;
    for(int main_counter = 1; main_counter <= rows; main_counter++)
    {
        out_counter = 0;
        for(int space_count = 1; space_count <= rows-main_counter; space_count++)
        {
            cout << "  ";
        }

        while(out_counter != 2*main_counter-1)
        {
            cout << out_char << " ";
            out_counter++;
        }
        cout << "\n";

}

    cout << "\n\n\n";
return;
}

void draw_square(char out_char, int rows, int columns)
{
    for (int counter = 1; counter <= rows; counter++)
    {


        for (int counter = 1; counter <=rows; counter++)
        {
            cout << out_char;
        }
        cout << "\n";

    }
    cout << "\n\n\n";
return;
}

void draw_diamond(char out_char, int rows, int columns)
{ /* code retrieved and modified from
    http://www.codebind.com/cpp-tutorial/cpp-program-to-print-diamond-of-stars/
    */
  int c, k, space = 1;
    space = rows - 1;

  for (k = 1; k<=rows; k++)
  {
    for (c = 1; c<=space; c++)
      cout<<" ";

    space--;

    for (c = 1; c<= 2*k-1; c++)
      cout<<"*";

    cout<<"\n";
  }

  space = 1;

  for (k = 1; k<= rows - 1; k++)
  {
    for (c = 1; c<= space; c++)
      cout<<" ";

    space++;

    for (c = 1 ; c<= 2*(rows-k)-1; c++)
      cout<<"*";

    cout<<"\n";
  }
    cout << "\n\n\n";
    return;
}

bool playagain()
{
    char value;
    bool done = true;
    bool switchdone = false;
    cout << "would you like to play again?";
    cin >> value;
    while (!switchdone)
    {
        switch(value)
            {
                case 'Y':
                case 'y':
                    switchdone = true;
                    break;
                case 'N':
                case 'n':
                    done = false;
                    switchdone = true;
                    break;
                default:
                    cout << "Please type that again";
                    break;
            }
    }
return done;
}

#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 2
#define COL5 A4
#define COL6 A3
#define COL7 A2
#define COL8 A1

const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {COL1, COL2, COL3, COL4, COL5, COL6, COL7, COL8};

int Z[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
               {0, 0, 0, 0, 0, 0, 1, 1},
               {0, 0, 0, 0, 0, 1, 0, 0},
               {0, 0, 0, 0, 1, 0, 0, 0},
               {0, 0, 0, 1, 0, 0, 0, 0},
               {0, 0, 1, 0, 0, 0, 0, 0},
               {0, 1, 0, 0, 0, 0, 0, 0},
               {1, 1, 1, 1, 1, 1, 1, 1}};

void setup()
{
  Serial.begin(9600);
  // Set the pin modes for the rows and columns
  for (int i = 2; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(A4, OUTPUT);
  digitalWrite(A4, LOW);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, LOW);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, LOW);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, LOW);
}

void loop()
{
  led(Z); // Call the led() function with the Z matrix
  delay(500);
}

void led(int matrix[8][8])
{
  for (int i = 0; i < 50; i++) // Repeat the LED display for a certain duration
  {
    for (int c = 0; c < 8; c++) // Iterate over the columns
    {
      digitalWrite(col[c], HIGH); // Activate the current column by setting it HIGH

      for (int r = 0; r < 8; r++) // Iterate over the rows
      {
        digitalWrite(row[r], 255 * matrix[r][c]); // Set the brightness of each row based on the matrix value
      }

      for (int r = 0; r < 8; r++) // Turn off all rows
      {
        digitalWrite(row[r], HIGH);
      }

      digitalWrite(col[c], LOW); // Deactivate the current column by setting it LOW
    }

    if (i == 49) // Break the loop after a certain number of iterations
    {
      break;
    }
  }
}

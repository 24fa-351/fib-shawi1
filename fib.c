#include <stdio.h>
#include <stdlib.h>

// Iterative Fibonacci function
int fibonacci_iterative(int n)
{
   if (n == 1)
      return 0; // Special case: F(1) = 0
   if (n == 2)
      return 1; // Special case: F(2) = 1

   int a = 0, b = 1, temp;
   for (int i = 3; i <= n; i++)
   {
      temp = a + b;
      a = b;
      b = temp;
   }
   return b; // Return 'b', which corresponds to F(n)
}

// Recursive Fibonacci function
int fibonacci_recursive(int n)
{
   if (n == 1)
      return 0; // Special case: F(1) = 0
   if (n == 2)
      return 1; // Special case: F(2) = 1

   return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main(int argc, char *argv[])
{
   if (argc != 4)
   {
      printf("Usage: %s <integer> <r|i> <filename>\n", argv[0]);
      return 1;
   }

   int input_num = atoi(argv[1]);
   char method = argv[2][0];
   char *filename = argv[3];

   // Open the file and read the integer
   FILE *file = fopen(filename, "r");
   if (file == NULL)
   {
      printf("Error: Could not open file %s\n", filename);
      return 1;
   }

   int file_num;
   fscanf(file, "%d", &file_num);
   fclose(file);

   // Add the input number and the file number to compute N
   int N = input_num + file_num;

   // Compute the Fibonacci number based on N
   int result;
   if (method == 'i')
   {
      result = fibonacci_iterative(N);
   }
   else if (method == 'r')
   {
      result = fibonacci_recursive(N);
   }
   else
   {
      printf("Invalid method. Use 'r' for recursive or 'i' for iterative.\n");
      return 1;
   }

   // Output only the Fibonacci number
   printf("%d\n", result);

   return 0;
}
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static int menu() {
        System.out.println("DISPLAY");
        System.out.println("1. All numbers");
        System.out.println("2. Even numbers");
        System.out.println("3. Subscripts (indices) of odd numbers");
        System.out.println("4. The numbers with even subscripts");
        System.out.println("5. Minimum number");
        System.out.println("6. Subscript of maximum number");
        System.out.println("7. Exit");
        
        Scanner scanner = new Scanner(System.in);
        int choice;
        do {
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
        } while (choice < 1 || choice > 7);
        
        scanner.close();
        
        return choice;
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the elements of the array: ");
        String numbersInput = scanner.nextLine();
        
        int[] numbers = Arrays.stream(numbersInput.split(" ")).mapToInt(Integer::parseInt).toArray();
        numbers = Arrays.copyOfRange(numbers, 0, numbers.length - 1);
        if (numbers.length > 100)
        {
            System.out.println("The number of elements must be less than or equal to 100");
            return;
        }
        
        int choice = 0;
        while (choice != 7) {
            choice = menu();
            switch (choice) {
                case 1:
                    System.out.println("All numbers:\n*************");
                    Arrays.stream(numbers).forEach(numb -> System.out.printf("%d ", numb));
                    System.out.println();
                    break;
                case 2:
                    System.out.println("Even numbers:\n*************");
                    Arrays.stream(numbers).filter(number -> number % 2 == 0).forEach(numb -> System.out.printf("%d ", numb));
                    System.out.println();
                    break;
                case 3:
                    System.out.println("Subscripts (indices) of odd numbers:\n*************");
                    for (int i = 0; i < numbers.length; i++) {
                        if (numbers[i] % 2 != 0) {
                            System.out.printf("%d ", i);
                        }
                    }
                    System.out.println();
                    break;
                case 4:
                    System.out.println("Subscripts (indices) of odd numbers:\n*************");
                    for (int i = 0; i < numbers.length; i++) {
                        if (i % 2 == 0) {
                            System.out.printf("%d ", numbers[i]);
                        }
                    }
                    System.out.println();
                    break;
                case 5:
                    System.out.println("Minimum number\n*************");
                    var min = Arrays.stream(numbers).min();
                    if (min.isEmpty()) {
                        System.out.println("ARRAY NOT VALID");
                        return;
                    }
                    System.out.println(min.getAsInt());
                    break;
                case 6:
                    System.out.println("Subscript of maximum number\n********************");
                    int maxIndex = 0;
                    for (int i = 1; i < numbers.length; i++) {
                        if (numbers[maxIndex] < numbers[i])
                            maxIndex = i;
                    }
                    System.out.println(maxIndex);
                    System.out.println();
            }
        }
        
        scanner.close();
    }
}
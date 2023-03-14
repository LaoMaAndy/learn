/*
 * Andy Lee
 */
import java.util.*;

/**
 * Break And Continue
 */
public class BreakAndContinue {
    int val;
    static class Init {
        int init;
        Init() {
            init = 0;
            System.out.println("constructor is run");
        }
    }
    public static void main(String[] args) {
        for (int i = 0; i < 100; i++) {
            if (i == 74) break;
            if (i % 9 != 0) continue;
            System.out.println(i + " ");
        }
        //System.out.println();
        int[] number = new int[100];
        for (int i = 0; i < number.length; i++)
            number[i] = i;
        for (int i : number) {
            if (i == 74) break;
            if (i % 9 != 0) continue;
            System.out.println(i + " ");
        }
        Random rand = new Random(100);
        for (int i = 0; i < 10; i++) {
            int n = rand.nextInt(10);
            System.out.println("Random: " + n);
        }
        for (int i = (int) 'a'; i < (int) 'z'; ++i)
            System.out.println((char) i + " is " + i);
        label1:
            System.out.println("This is a lable");
        feb(10);
        vimp();
    }
    public static void feb(int n) {
        int a, b;
        int[] sum = new int[n];
        Init it = new Init();
        a = b = 1;
        sum[0] = sum[1] = 1;
        System.out.println("Fibonaci: ");
        System.out.println("0: " + sum[0]);
        System.out.println("1: " + sum[1]);
        for (int i = 2; i < n; ++i) {
            sum[i] = sum[i - 1] + sum[i - 2];
            System.out.println(i + ": " + sum[i]);
        }
    }
    public static void vimp() {
        int[] startDigit = new int[4];
             int[] productDigit = new int[4];
             for(int num1 = 10; num1 <= 99; num1++)
               for(int num2 = num1; num2 <= 99; num2++) {
                 // Pete Hartley's theoretical result:
                 // If x·y is a vampire number then
                 // x·y == x+y (mod 9)
                 if((num1 * num2) % 9 != (num1 + num2) % 9)
                   continue;
                 int product = num1 * num2;
                 startDigit[0] = num1 / 10;
                 startDigit[1] = num1 % 10;
                 startDigit[2] = num2 / 10;
                 startDigit[3] = num2 % 10;
                 productDigit[0] = product / 1000;
                 productDigit[1] = (product % 1000) / 100;
                 productDigit[2] = product % 1000 % 100 / 10;
                 productDigit[3] = product % 1000 % 100 % 10;
                 int count = 0;
                 for(int x = 0; x < 4; x++)
                   for(int y = 0; y < 4; y++) {
                     if(productDigit[x] == startDigit[y]) {
                       count++;
                       productDigit[x] = -1;
                       startDigit[y] = -2;
                       if(count == 4)
                        System.out.println(num1 + " * " + num2
                       + " : " + product);
                    } 
                }
            } 
    }
} 

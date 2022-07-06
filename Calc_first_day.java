package ru.ac.uniyar.mf.summer;

import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        String first_num, second_num, operator;
        int numerator, denominator, type_calc;
        double f_num, s_num;
        String[] first_fraction, second_fraction;
        Scanner in = new Scanner(System.in);

        System.out.println("Выберите тип калькулятора: ");
        System.out.println("1) Десятичные дроби");
        System.out.println("2) Обыкновенные дроби");
        type_calc = in.nextInt();

        System.out.println("Введите выражение: ");

        if (type_calc == 1) {
            f_num = in.nextDouble();
            operator = in.next();
            s_num = in.nextDouble();

            switch (operator) {
                case "+":
                    System.out.println(f_num + s_num);
                    break;
                case "-":
                    System.out.println(f_num - s_num);
                    break;
                case "*":
                    System.out.println(f_num * s_num);
                    break;
                case "/":
                    if (s_num == 0) System.out.println("Деление на ноль!");
                    else System.out.println(f_num / s_num);
                    break;
            }
        }

        if (type_calc == 2) {
            first_num = in.next();
            operator = in.next();
            second_num = in.next();

            first_fraction = first_num.split("/");
            second_fraction = second_num.split("/");

            switch (operator) {
                case "+":
                    if (Integer.parseInt(first_fraction[1]) != Integer.parseInt(second_fraction[1])) {
                        denominator = Integer.parseInt(first_fraction[1]) * Integer.parseInt(second_fraction[1]);
                        int f_numerator = Integer.parseInt(first_fraction[0]) * Integer.parseInt(second_fraction[1]);
                        int s_numerator = Integer.parseInt(first_fraction[1]) * Integer.parseInt(second_fraction[0]);
                        numerator = f_numerator + s_numerator;
                    } else {
                        numerator = Integer.parseInt(first_fraction[0]) + Integer.parseInt(second_fraction[0]);
                        denominator = Integer.parseInt(first_fraction[1]);
                    }
                    System.out.println(numerator + "/" + denominator);
                    break;
                case "-":
                    if (Integer.parseInt(first_fraction[1]) != Integer.parseInt(second_fraction[1])) {
                        denominator = Integer.parseInt(first_fraction[1]) * Integer.parseInt(second_fraction[1]);
                        int f_numerator = Integer.parseInt(first_fraction[0]) * Integer.parseInt(second_fraction[1]);
                        int s_numerator = Integer.parseInt(first_fraction[1]) * Integer.parseInt(second_fraction[0]);
                        numerator = f_numerator - s_numerator;
                    } else {
                        numerator = Integer.parseInt(first_fraction[0]) - Integer.parseInt(second_fraction[0]);
                        denominator = Integer.parseInt(first_fraction[1]);
                    }
                    System.out.println(numerator + "/" + denominator);
                    break;
                case "*":
                    numerator = Integer.parseInt(first_fraction[0]) * Integer.parseInt(second_fraction[0]);
                    denominator = Integer.parseInt(first_fraction[1]) * Integer.parseInt(second_fraction[1]);
                    System.out.println(numerator + "/" + denominator);
                    break;
                case "/":
                    numerator = Integer.parseInt(first_fraction[0]) * Integer.parseInt(second_fraction[1]);
                    denominator = Integer.parseInt(first_fraction[1]) * Integer.parseInt(second_fraction[0]);
                    System.out.println(numerator + "/" + denominator);
                    break;
            }
        }
    }
}

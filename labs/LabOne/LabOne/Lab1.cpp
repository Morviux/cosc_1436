/*
 Lab 1
 Demetris Lincoln
 COSC 1436 Spring 2026
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

void main()
{
    std::string name;
    int labOneGrade, labTwoGrade, labThreeGrade, labFourGrade;

    int examOne, examTwo, examThree;

    int partGrade;
    int finalExam; 
    
    double labAverage;
    double examAverage;
    double classAverage;
    
    std::cout << "Lab One " << std::endl;
    std::cout << "By: Demetris L. Lincoln " << std::endl;
    std::cout << "COSC 1436 - Spring 2026 " << std::endl;

    std::cout << std::endl;

    std::cout << "Enter Your Name: ";
    std::cin >> name;

    std::cout << std::endl;

    std::cout << "Enter your grade for lab 1: ";
    std::cin >> labOneGrade;
    std::cout << "Enter your grade for lab 2: ";
    std::cin >> labTwoGrade;
    std::cout << "Enter your grade for lab 3: ";
    std::cin >> labThreeGrade;
    std::cout << "Enter your grade for lab 4: ";
    std::cin >> labFourGrade;

    std::cout << std::endl;

    std::cout << "Enter exam 1 grade: ";
    std::cin >> examOne;
    std::cout << "Enter exam 2 grade: ";
    std::cin >> examTwo;
    std::cout << "Enter exam 3 grade: ";
    std::cin >> examThree;

    std::cout << std::endl; 

    std::cout << "Enter participation grade: ";
    std::cin >> partGrade;

    std::cout << std::endl;

    std::cout << "Enter final exam grade: ";
    std::cin >> finalExam;

    // Calculations for both labs and exams - Casted the numbers into doubles 
    labAverage = (static_cast<double>(labOneGrade + labTwoGrade + labThreeGrade + labFourGrade) / 4);
    examAverage = (static_cast<double>(examOne + examTwo + examThree) / 3);
    classAverage = (labAverage * 0.65) + (examAverage * 0.20) + (partGrade * 0.05) + (finalExam * .10);

    std::cout << std::endl;

    std::cout << name << ", your lab grades are... " << std::endl;
    std::cout << "Lab 1: " << labOneGrade << std::endl;
    std::cout << "Lab 2: " << labTwoGrade << std::endl;
    std::cout << "Lab 3: " << labThreeGrade << std::endl;
    std::cout << "Lab 4: " << labFourGrade << std::endl;

    std::cout << std::endl;

    std::cout << name << ", your exam grades are... " << std::endl;
    std::cout << "Exam 1: " << examOne << std::endl;
    std::cout << "Exam 2: " << examTwo << std::endl;
    std::cout << "Exam 3: " << examThree << std::endl;

    std::cout << std::endl;

    std::cout << name << ", your other grades are.. " << std::endl;
    std::cout << "Participation: " << partGrade << std::endl;
    std::cout << "Final exam: " << finalExam << std::endl; 

    std::cout << std::endl;

    std::cout << "Lab Average " << "(65% of your grade): " << std::fixed << std::setprecision(2) << labAverage << "%!" << std::endl;
    std::cout << "Exam Average " << "(20% of your grade): " << std::fixed << std::setprecision(2) << examAverage << "%!" << std::endl;
    std::cout << "Participation " << "(5% of your grade) " << std::fixed << std::setprecision(2) << partGrade << "%!" << std::endl;
    std::cout << "Final Exam " << "(10% of your grade) " << std::fixed << std::setprecision(2) << finalExam << "%!" << std::endl;

    std::cout << std::endl;

    std::cout << "Class Average? " << std::fixed << std::setprecision(2) << classAverage << "%!" << std::endl;
}
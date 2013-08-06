#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

int main()
{
    char Population_Alpha_Input_File_Name[50],Population_Beta_Input_File_Name[50];
    int Orbital_Num_Count=1,Orbital_Number;  
    double Population[23][408], Population_Alpha[23][408], Population_Beta[23][408], Seven_D_Total[408],Eight_D_Total[408];
    double Alpha_1,Alpha_2,Alpha_3,Alpha_4,Alpha_5,Beta_1,Beta_2,Beta_3,Beta_4,Beta_5;
     

    //Get filename from keyboard input
    cout << "Please enter alpha file name: ";
    cin >> Population_Alpha_Input_File_Name;
    cout << "Please enter beta file name: ";
    cin >> Population_Beta_Input_File_Name;
    cout <<"Please enter orbital number: ";
    cin >> Orbital_Number;

    //Input from file
    ifstream PopulationAlphaInput;
    PopulationAlphaInput.open(Population_Alpha_Input_File_Name);
    ifstream PopulationBetaInput;
    PopulationBetaInput.open(Population_Beta_Input_File_Name);    

    //Initialize output streams
    ofstream PopulationOutput;
    PopulationOutput.open("Population_Output_File.dat"); 
    ofstream OrbitalOutput;
    OrbitalOutput.open("Orbital_Output_File.dat");
    ofstream D_Orbital_Output;
    D_Orbital_Output.open("D_Orbital_OutFile.txt"); 

    //Declare stringstream
//    stringstream Population_Stream;
    
    while(PopulationAlphaInput.good()== false)
    {
    cout << "Unable to open cubegen file. Enter a new name: ";
    cin >> Population_Alpha_Input_File_Name;
    // Clear the file stream
    PopulationAlphaInput.clear();
    PopulationAlphaInput.open(Population_Alpha_Input_File_Name);
    }
    
    while(PopulationBetaInput.good()== false)
    {
    cout << "Unable to open cubegen file. Enter a new name: ";
    cin >> Population_Beta_Input_File_Name;
    // Clear the file stream
    PopulationBetaInput.clear();
    PopulationBetaInput.open(Population_Beta_Input_File_Name);
    }

    while(Orbital_Num_Count<411)
    {
    PopulationOutput << "\n";
    PopulationOutput <<Orbital_Num_Count<<" "<<Orbital_Num_Count+1<<" "<<Orbital_Num_Count+2<<" "<<Orbital_Num_Count+3<<" "<<Orbital_Num_Count+4<<endl;
    PopulationOutput << "\n"; 
         for (int j=1;j<23;j++) 
         {
        
           PopulationAlphaInput >> Alpha_1 >> Alpha_2 >> Alpha_3 >> Alpha_4 >> Alpha_5;
                      
           Population_Alpha[j][Orbital_Num_Count]=Alpha_1;
           Population_Alpha[j][Orbital_Num_Count+1]=Alpha_2;
           Population_Alpha[j][Orbital_Num_Count+2]=Alpha_3;
           Population_Alpha[j][Orbital_Num_Count+3]=Alpha_4; 
           Population_Alpha[j][Orbital_Num_Count+4]=Alpha_5;        
  
           PopulationBetaInput >> Beta_1 >> Beta_2 >> Beta_3 >> Beta_4 >> Beta_5;

           Population_Beta[j][Orbital_Num_Count]=Beta_1;
           Population_Beta[j][Orbital_Num_Count+1]=Beta_2;
           Population_Beta[j][Orbital_Num_Count+2]=Beta_3;
           Population_Beta[j][Orbital_Num_Count+3]=Beta_4;
           Population_Beta[j][Orbital_Num_Count+4]=Beta_5;           

         
        //   PopulationOutput <<j<<" "<< Population[j][Orbital_Num_Count] <<" "<< Population[j][Orbital_Num_Count+1]<<" "<<Population[j][Orbital_Num_Count+2]<<" "<<Population[j][Orbital_Num_Count+3]<<" "
        //   <<Population[j][Orbital_Num_Count+4]<<"\n";        
           
          } 
    Orbital_Num_Count=Orbital_Num_Count+5;
    }
  
    for(int i=1;i<409;i++)
    {
       for(int j=1;j<23;j++)
       {
       Population[j][i]=Population_Alpha[j][i]+Population_Beta[j][i];
       }

    } 

    for(int n=1;n<23;n++)
    {
    OrbitalOutput <<n<<" "<< abs(Population[n][Orbital_Number]) << "\n";

    }

    for(int i=1;i<409;i++)
    {
       for(int j=13;j<18;j++)
       {
       Seven_D_Total[i]=Seven_D_Total[i]+abs(Population[j][i]);
       } 

       for(int n=18;n<23;n++)
       {
       Eight_D_Total[i]=Eight_D_Total[i]+abs(Population[n][i]);
       }


    }

    D_Orbital_Output <<"7D_0"<<" "<<"7D_1"<<" "<<"7D_Minus1"<<" "<<"7D_2"<<" "<<"7D_Minus2"<<" "<<"8D_0"<<" "<<"8D_1"<<" "
    <<"8D_Minus1"<<" "<<"8D_2"<<" "<<"8D_Minus2"<<" "<<"7D_Total"<<" "<<"8D_Total"<<endl;
    
    for(int i=1;i<409;i++)
    {
    D_Orbital_Output<< i <<" "<<abs(Population[13][i])<<" "<<abs(Population[14][i])<<" "<<abs(Population[15][i])<<" "<<abs(Population[16][i])<<" "<<abs(Population[17][i])<<" "
    <<abs(Population[18][i])<<" "<<abs(Population[19][i])<<" "<<abs(Population[20][i])<<" "<<abs(Population[21][i])<<" "<<abs(Population[22][i])<<" "<<Seven_D_Total[i]<<" "<<Eight_D_Total[i]
    <<endl;
    }
return 0;
}

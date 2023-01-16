/*firstly created a 3D vector in which each 2D vector will represent a  block 
-> so I will count maxrow from all the block. and start filling first asile ->window->middle


=>>as we have to first fill a row completely then next  row for respective seats.   so we will traverse row wise
for asile seats  =>>>  as asile seat will be last column for 1st block and 1st column for last block and for middle blocks it will be 1st and last col

for window seat  =>>>  as window seat will be 1st column of 1st block and last column of last block so will fill them accordingly

for middle seat  =>>>  for middle seat in each block we will iterate from 2nd column to one column before to last column

=>> in every iteration we will take a counter for seat no. after assigning we will increase it and will check if it is greater than total no. of 
passaenger then we will get out of loop


and then we will print accordingly


example=>
inputs:
2 22
3 4 4 5

output:
10 19 1 2 20 21 11 
12 0 3 4 0 0 13 
14 0 5 6 0 0 15 
16 0 7 8 0 0 17 
      9 0 0 18 



*/


#include <bits/stdc++.h>
using namespace std;

void seatFunction(vector<vector<vector<int>>>&seating,int num_pass){
                                                                           //we will traverse it row-wise assign seat row-wise so we will define 
    int curr_seat=1;                                                      //max row that we can go up to.
    int maxrow=0;
    for(int k=0;k<seating.size();k++){
       if(seating[k].size()>maxrow) maxrow=seating[k].size();
    }                                                                      //here k is total no. of 2D block present in seating arrangement


    //for asile seat
    for(int row=0;row<maxrow;row++){                                   // we will traverse row wise first assign all asile seat to passesnger. In a row we will taverse all colums of each block
        for(int k=0;k<seating.size();k++){                            
            if(row<seating[k].size())                                  //through this loop we will firstly iterate over complete arrangement and assign asile seat 
            {
            if(k>0&&k<seating.size()-1){
                   
                        seating[k][row][0]=curr_seat;
                        curr_seat++;
                        if(curr_seat>=num_pass) break;
                         seating[k][row][seating[k][0].size()-1]=curr_seat;       //to fill asile seat of middle blocks in this we have to fill both starting and ending seat of a bloack 
                                                              // and we will assign respective seat no. to them
                        curr_seat++;
                    
                }
                else if(k==0) seating[k][row][seating[k][0].size()-1]=curr_seat++;     //as for side blocks (first and last we only have to assign corner seat)
                else if(k==seating.size()-1) seating[k][row][0]=curr_seat++;
                if(curr_seat>=num_pass) break;
           }
           if(curr_seat>=num_pass) break;
        }
         if(curr_seat>=num_pass) break;
    }


//for window seat
for(int row=0;row<maxrow;row++){
        for(int k=0;k<seating.size();k++){             //through this loop we will firstly iterate over complete arrangement and assign window seat 
            if(row<seating[k].size())
            {
                if(k==0) seating[k][row][0]=curr_seat++;                                                      //window seat is only present in first bloack  and last block so 
                else if(k==seating.size()-1) seating[k][row][seating[k][0].size()-1]=curr_seat++;                  //we'll traverse through every row and assign window seat  
                if(curr_seat>=num_pass) break;                                                                //to starting column of 1st block and last colums of last block           
           }
        }
         if(curr_seat>=num_pass) break;
    }    
    
//for middle seat
    for(int row=0;row<maxrow;row++){
        for(int k=0;k<seating.size();k++){            //through this loop we will firstly iterate over complete arrangement and assign middle seat 
            if(row<seating[k].size())
            {
                for(int col=1;col<seating[k][0].size()-1;col++){          //middle seat is present in each block from 2nd colums to   
                      seating[k][row][col]=curr_seat;                   //2nd last column so we'll traverse through every row
                                                        //and assign middle seat from 2nd colums to 2nd last column in each block
                       curr_seat++;
                        if(curr_seat>=num_pass) break;
                    } 
                    if(curr_seat>=num_pass) break;
            }
        }
               
                if(curr_seat>=num_pass) break;
    }
 // for printing all the arranngement
    for(int row=0;row<maxrow;row++){                               
         for(int k=0;k<seating.size();k++){
            
            if(row<seating[k].size()){
               
                for(int col=0;col<seating[k][row].size();col++ ){
                    cout<<seating[k][row][col]<<" ";
                }
            }
            else if(row>=seating[k].size()){
               for(int col=0;col<seating[k][0].size();col++){
                  cout<<" ";
               }
               cout<<" ";
            }

         }
         cout<<endl;  
        
}
}



int main(){
    int block_size;
    int num_passenger;
    
    cin>>block_size;
    cin>>num_passenger;
    vector<vector<vector<int>>>seating;
    while(block_size--){
        int row,col;
        cin>>col>>row;
        vector<vector<int>>block(row,vector<int>(col));
        seating.push_back(block);
    }

    seatFunction(seating,num_passenger);
    
    return 0;
}
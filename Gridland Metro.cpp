#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool wayToSort (vector<size_t> &i,vector<size_t> &j) 
{
    if (i[0]<j[0])      return 1;       //sort the vector ascending depending on the value of the first column
    else if (i[0]>j[0]) return 0;       
    return (i[1]<j[1]) ;                //if 2 cells of first column are equal then sort depending on the value of the second column
}

size_t gridlandMetro(size_t n, size_t m, size_t k, vector < vector<size_t> > &track)
{
    size_t metro = 0;                              //number of cells we cant insert lampposts 
    sort(track.begin(), track.end(), wayToSort);   //sort depending on function wayToSort
    if(k){                                         //if k = 0 then metro aslo = 0 we dont need to do calculations;
    for(size_t i=0 ; i<k-1 ; ++i) 
    {
        if(track[i][0]==track[i+1][0])             //if the second entry in the same row of the city
        {
            if(track[i+1][1]<=track[i][2])         //if the starting of next entry is less than the end then we detect an ovlerlap 
                if(track[i+1][2]>track[i][2])      //if the end of next entry is greater than the end then extend the next entry
                    track[i+1][1]=track[i][1] ;
                else                               //if the next end is less than the end extend the next 
                {track[i+1][1]=track[i][1] ;track[i+1][2]=track[i][2] ;}
            else
                metro += ( track[i][2]-track[i][1]+1 );  //if we dont have overlap add the length of last extended length
        }
        else
            metro += ( track[i][2]-track[i][1]+1 );      //if the next is in another row add the length if last extended length
    }
    k--;
    metro += ( track[k][2]-track[k][1]+1 );}            //because the loop doesnt reach the last entry 
    
    
    return ((m*n)-metro);                              //return all spaces - metro spaces
}

int main() 
{
    size_t n;
    size_t m;
    size_t k;
    cin >> n >> m >> k;
    vector< vector<size_t> > track(k,vector<size_t>(3));
    for(size_t track_i = 0;track_i < k;track_i++){
       for(size_t track_j = 0;track_j < 3;track_j++){
          cin >> track[track_i][track_j];
       }
    }
    size_t result = gridlandMetro(n, m, k, track);
    cout << result << endl;
    return 0;
}

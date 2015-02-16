//
//  main.cpp
//  CoastLength
//
//  Created by Stefán Hafsteinsson on 10/12/14.
//  Copyright (c) 2014 Stefán Hafsteinsson. All rights reserved.
//

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool world[1010][1010];


void addSea(int N, int M)
{
    for(int i = 0; i < N; i++)
    {
        world[i][0] = false;
        world[i][M - 1] = false;
    }
    
    for(int i = 0; i < M; i++)
    {
        world[0][i] = false;
        world[N - 1][i] = false;
    }

}

int bfs(int N, int M)
{
    int count = 0;
    bool visited[1010][1010];
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> Q;
    Q.push(pair<int, int>(0, 0));
    visited[0][0] = true;
    
    while (!Q.empty())
    {
        int v = Q.front().first;
        int w = Q.front().second;
        Q.pop();
        
        //Check left.
        if(v > 0 && !visited[v - 1][w] && !world[v][w])
        {
            if(!world[v - 1][w])
            {
                Q.push(pair<int, int>(v - 1, w));
                visited[v - 1][w] = true;
            }
            else if(world[v - 1][w])
            {
                count++;
            }
            
        }
        
        
        
        //Check right.
        if(v < N - 1 && !visited[v + 1][w] && !world[v][w])
        {
            if(!world[v + 1][w])
            {
                Q.push(pair<int, int>(v + 1, w));
                visited[v + 1][w] = true;
            }
            else if(world[v + 1][w])
            {
                count++;
            }
            
            
        }
        
        //Check up.
        if(w > 0 && !visited[v][w - 1] && !world[v][w])
        {
            if(!world[v][w - 1])
            {
                Q.push(pair<int, int>(v, w - 1));
                visited[v][w - 1] = true;
            }
            else if(world[v][w - 1])
            {
                count++;
            }
            
        }
        
        //Check down.
        if(w < M - 1 && !visited[v][w + 1] && !world[v][w])
        {
            
            if(!world[v][w + 1])
            {
                Q.push(pair<int, int>(v, w + 1));
                visited[v][w + 1] = true;
            }
            else if(world[v][w + 1])
            {
                count++;
            }
            
        }
        
        
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    int N, M;
    char square;
    
    scanf("%d%d", &N, &M);
    
    N += 2;
    M += 2;
    
    addSea(N, M);
    
    for(int i = 1; i < N - 1; i++)
    {
        
        for(int j = 1; j < M - 1; j++)
        {
            cin >> square;
            
            if(square == '1')
            {
                world[i][j] = true;
            }
            else
            {
                world[i][j] = false;
            }
        }
    }
    

    /*for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cout << world[i][j] << " ";
        }
        
        cout << endl;
    }*/
    
    cout << bfs(N, M) << endl;

    
    return 0;
}

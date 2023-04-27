// #include <bits/stdc++.h>
// using namespace std;
// int sum(int freq[], int i, int j);
// int optCost(int freq[], int i, int j)
// {

// 	if (j < i)
// 		return 0;
// 	if (j == i) 
// 		return freq[i];

// 	int fsum = sum(freq, i, j);

// 	int min = INT_MAX;

// 	for (int r = i; r <= j; ++r)
// 	{
// 		int cost = optCost(freq, i, r - 1) +
// 				optCost(freq, r + 1, j);
// 		if (cost < min)
// 			min = cost;
// 	}
	
// 	return min + fsum;
// }

// int optimalSearchTree(int keys[],
// 					int freq[], int n)
// {

// 	return optCost(freq, 0, n - 1);
// }

// int sum(int freq[], int i, int j)
// {
// 	int s = 0;
// 	for (int k = i; k <= j; k++)
// 	s += freq[k];
// 	return s;
// }

// int main()
// {
// 	int keys[] = {10, 12, 20};
// 	int freq[] = {34, 8, 50};
// 	int n = sizeof(keys) / sizeof(keys[0]);
// 	cout << "Cost of Optimal BST is "
// 		<< optimalSearchTree(keys, freq, n);
// 	return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// int max(int a, int b) { return (a > b) ? a : b; }
// int knapSack(int W, int wt[], int val[], int n)
// {
// 	if (n == 0 || W == 0)
// 		return 0;
// 	if (wt[n - 1] > W)
// 		return knapSack(W, wt, val, n - 1);
// 	else
// 		return max(
// 			val[n - 1]
// 				+ knapSack(W - wt[n - 1], wt, val, n - 1),
// 			knapSack(W, wt, val, n - 1));
// }
// int main()
// {
// 	int profit[] = { 60, 100, 120 };
// 	int weight[] = { 10, 20, 30 };
// 	int W = 50;
// 	int n = sizeof(profit) / sizeof(profit[0]);
// 	cout << knapSack(W, weight, profit, n);
// 	return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// class job
// {
// public:
//     char module;
//     int node;
//     int color;
//     queue()
//     {
//     }
//     check_thecomplete_(char id, int dead, int profit)
//     {
//         this->id = id;
//         this->dead = dead;
//         this->profit = profit;
//     }
// };

// bool comparison(job a, job b)
// {
//     return a.profit > b.profit;
// }

// void graph_coloringjob arr[], int n)
// {
//     sort(arr, arr + n, comparison);

//     int result[n];
//     bool slot[n] = {false};

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
//         {
//             if (!slot[j])
//             {
//                 result[j] = i;
//                 slot[j] = true;
//                 break;
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[result[i]].id << " ";
//     }
// }

// int main()
// {
// 	job arr[] ={{'a', 4, 100}, {'b', 4, 98}, {'c', 4, 54}, {'d', 1, 25}, {'e', 3, 15}};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     jobScheduling(arr, n);
//     return 0;
// }

// #include <iostream>
// #include <stack>
 
// using namespace std;
 
// int set[] = {10, 7, 5, 18, 12, 20, 15};
// int numberOfElements = 7, sum = 30;
 
// class SubSet{
// public:
//   stack<int> solutionSet;
//   bool hasSolution;
  
//   void solve(int s, int idx){
//     if(s>sum)
//         return;
//     if(s==sum){
//         hasSolution = true;
//         displaySolutionSet();
//         return;
//     }
        
 
//     for(int i=idx; i<numberOfElements; i++){
//         solutionSet.push(set[i]);
//         solve(s+set[i],i+1);
//         solutionSet.pop();
//     }
//   }
//   void displaySolutionSet(){
//         stack<int> temp;
      
//         while (!solutionSet.empty()) 
//         { 
//             cout <<  solutionSet.top() << " "; 
//             temp.push(solutionSet.top()); 
//             solutionSet.pop();
//         } 
//         cout << '\n';
//         while (!temp.empty()) 
//         { 
//             solutionSet.push(temp.top()); 
//             temp.pop();
//         } 
//     }
// };
 
// int main()
// {
//     SubSet ss;
//     ss.solve(0,0);
	    
// 	if(ss.hasSolution == false)
// 	    cout << "No Solution";
 
//     return 0;
// }




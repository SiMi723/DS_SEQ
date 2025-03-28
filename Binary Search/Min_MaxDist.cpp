//Problem Link
//https://www.naukri.com/code360/problems/minimise-max-distance_7541449?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=SUBMISSION


//Brute force
long double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howMany(n-1, 0);
	for(int gasStations = 1; gasStations <= k; gasStations++) {
		long double maxSection = -1;
		int maxInd = -1;
		for(int i = 0;i<n-1;i++) {
			long double diff = (arr[i+1]-arr[i]);
			long double sectionLengtj = diff /(long double)(howMany[i] + 1);
			if(sectionLengtj > maxSection) {
				maxSection = sectionLengtj;
				maxInd = i;
			}
		}
		howMany[maxInd]++;

	}
	long double maxAns = -1;
	for(int i = 0; i < n-1; i++) {
		long double diff = (arr[i+1]-arr[i]);
		long double sectionLengtj = diff /(long double)(howMany[i] + 1);
		maxAns = max(maxAns, sectionLengtj);
	}
	return maxAns;
	// Write your code here.	
}
//Better Solution
#include<bits/stdc++.h>
long double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	vector<int> howMany(n-1, 0);
	priority_queue<pair<long double, int>> pq;
	for(int i = 0;i<n-1;i++) {
		pq.push({arr[i+1]-arr[i], i});//nlogn...T.C
	}
	for(int gasStations = 1; gasStations <= k; gasStations++) {
		auto tp = pq.top();pq.pop();
		int secInd = tp.second;
		howMany[secInd]++;
		long double iniDiff = arr[secInd + 1] - arr[secInd];
		long double newSecLen = iniDiff / (long double)(howMany[secInd]+ 1);
		pq.push({newSecLen, secInd});
		//klogn ...T.C
	}
	//s.c (n-1)
	return pq.top().first;
	// Write your code here.	
}
//Optimal Solution
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
	int cnt = 0;
	for(int i = 1; i < arr.size();i++) {
		int numberInBetween = ((arr[i]-arr[i-1])/dist);
		if((arr[i]-arr[i-1]) / dist == numberInBetween * dist) {
			numberInBetween--;
		}
		cnt += numberInBetween;
	}
	return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
	int n = arr.size();
	long double low = 0;
	long double high = 0;
	for(int i = 0;i <n-1;i++) {
		high = max(high, (long double)(arr[i+1]-arr[i]));
	}

	long double diff = 1e-6;
	while(high-low > diff) {
		long double mid = (low + high) / (2.0);
		int cnt = numberOfGasStationsRequired(mid, arr);
		if(cnt > k) {
			low = mid;
		} else {
			high = mid;
		}
	}
	return high;	
}
//T.C--(O(nlogn+n))
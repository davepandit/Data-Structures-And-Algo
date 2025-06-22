`Those who cannot remember the past are condemned to repeat it🐣`

`We know that whenever we are asked to find out min of all the ways, all ways, max of all ways, count all ways, basically when we need to explore all ways then we can think of recursion, and later on we can think whether isme dynamic programming lag raha hai ya nahi and all🥚`

#### How to convert a recurrence relation into a `dp soln`?

- Fist see that how many parameters are changing in the recursive function 
- Make a dp array of that order 
- Before returning the ans store the ans in the dp array 
- Before calling the function just check whether the result is already present in the dp array or not

#### How to convert a memoization soln into a `tabulation soln`?

- Declare base case
- Express all states in `for loop`
- Copy the recurrence and write it as it is 

#### How can we do `space optimisation` after we have written the tabulation sol?

- If the recurrence relation is only depending on the immediate prev things then we can surely do space space optimisation

#### In majority of the cases in the DP problem the time complexity is O(n)(atleast for the 1d array problems), not very sure but this is because only the left subtree is computed and the values are stored and hence are re-utilised later

### In order to write any recurrence relation we need to know two things - `kya karna hai` + `kahan jaana hai`

- In Day 3 we will be solving the problem where we have to do something with the subsequence or subsest and with a target 


#### Note - One very imp point -
- If we are asked to return min, max then 
- In while writing the recurrence relation there is a possibily that 
- We need to return min(take, notTake) or max(take, notTake) ans hence we need to do `kya karna hai`
- Otherwise the step `kya karna hai + kahana jaana hai` isme explicitly `kya karna hai` karke fayda nahi hai wo kahi na kahi automatically adjust ho jaata hai 
- And in those problems where min, max nahi laga raha hai there is a possibility that we need to do the sum of `take + notTake`
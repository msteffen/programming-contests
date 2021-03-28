First issue: I realized that I needed longs (8-byte) instead of ints (4-byte)
to hold the total cost of getting to the end for some of the test cases.
running_on_fumes_chapter_1_validation_output.int.txt and
running_on_fumes_chapter_1_validation_output.ull.txt the outputs of the two
versions of my program
-------
Second issue

My solution was accidentally N^2 instead of N, which caused me to use up my
time and miss the submission. At each node N_i, I would scan all nodes in
N_{i+1} to N_{i+M} and update the cost to get to them if it's lower than the
currently-recorded best. This is like some kind of graph reachability
algorithm, but I think it has N^2 runtime in the case where the cost of gas at
each node is monotonically decreasing down the line. Each node will update more
and more of the downstream nodes as its gas price is $1 less than the price of
the node before it.

Previous comment:
> Basically, I started at the beginning and then tried to figure out which towns
> I could get to cheaply. Instead, I think I needed to start at the end. Once I
> find a minimal-cost town that can get me to the end, there's no reason to
> investigate towns any farther along the road than that: 1. Scan N-1,N-2,...,N-M
> to see which has the lowest C_i
>
> Then, I can repeat the this algorithm before this "last cheap town"--what's the cheapest way to get to the last cheap town?

On thinking about it some more, I don't think the key is to start at the end, I
think the key may be to construct a more efficient representation of "how much
does it cost to get to node i". Previously, in the "monotonically decreasing"
case, advancing to a subsequent, cheaper node would cause N updates. But if I
maintain a sorted list or map[index]->price, and encountering a node <i, C_i>
incurs the following update:

1. Add <i+M, P_i + C_i> to Map (where P_i is "price to get to i" or "Map[k]
where k is the smallest value in map that is >= i"
2. Remove all <k,v>s where there exists some <k',v'> with k' ≥ k and v' ≤ v
(i.e. Map should be monotonic: a < b => Map[a] < Map[b])

Then the "monotonically decreasing gas prices" case becomes N instead of N^2:
at each step, add a <k,v> for the new node, and remove the <k-1, v+ε> added for
the prior node.

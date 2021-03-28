I think for values of N>3, you can reassemble the stone if |A| > |B|/2 and |B| > |A|/2:

A..A[AAB]B..B -> A..AB..B. By some variant of the pigeonhole principle, you can
always find two copies of the more common letter adjacent to each other, and
then you can keep reducing those until you're done or you have a string of the
form ABABABA and those can always be reduced from the left (ABA... -> A...).

Unfortunately my solution in this vein is being rejected, and I'm not sure why...
----
**Update** I had the right idea but the wrong solution. You can't reduce the
letters if the difference is >1 (i.e. ≥3, as the total cound is odd, so one
must be even and one must be odd and the greater minus the lesser must also be
odd), not if the difference is larger than a half. The fact that my criterion
didn't work for N=2 should have been a clue.

Basically, to reduce you need an A, a B, and a wildcard. The wildcard, if
incorporated into another expression stays the same:
  A[ABB]B -> ABB -> B
    ☝        ☝
 wildcard  wildcard

So given 'A..{N}..ABB..{N}..B', you will eliminate the N A's and the N B's,
and the B in the middle stays the same, in some sense. Thus if you have more
than one wildcard, the reduction won't work.

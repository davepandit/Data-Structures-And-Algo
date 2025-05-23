## What if we want to check whether a bit is set or not?

Say the number given to us is ```num```.

Now we need to check the ```i```th bit from the right whether that is a set bit or not?

We can do this using ->  ```(num >> i) & 1``` == 1, then that bit is a set bit.

## What if we want to turn a bit?

Say the number given to us is ```num```.

Now we want to turn the ```i```th bit from the right.

We can do this thing using -> ```(1 << i) | num```


```One very important thing to note over here is 'i' is always from the right.```
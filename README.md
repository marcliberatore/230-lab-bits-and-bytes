# COMPSCI 230 Fall 2022
# Set with Bit Vectors

In this lab we will implement a "bit vector" or "bitset" -- a way of representing set 
membership, on the basis of a sequence of bits that assigned the value 1 or 0. First, we'll implement a bitset using a single 32-bit unsigned integer. Then, we'll look at how to generalize it to an array of such integers. Finally, if time permits, we'll explore how to address the individual bits in the set using only shifts -- that is, without the use of arithmetic operations. (Division and modulus in particular can be slow compared to bit shifts.)

To start working on this lab you must be logged in to the Edlab and in your `cs230` directory, or be in a similar environment on your local machine. 

From this directory run the command:

```
$ git clone https://github.com/marcliberatore/230-lab-bits-and-bytes
```

to make a copy of this lab directory, or use [Github Desktop](https://desktop.github.com), or download and decompress a zip file directly from Github to use locally (the green "Code" button has a "Download ZIP" option). 

## Part 1: A single `unsigned int` bitset

First, we'll represent a set of up to 32 items using an `unsigned int` called `I`.  Each *bit* in `I` represents a unique element. If a certain element is contained in our
set, then the bit in `I` corresponding to that element is turned to 1, otherwise
0. We order the bits in `I` from the least significant bit to the most. Consider the
following example.

Suppose we have a collection of fruits. One way to represent them is to order them alphabetically and assign each fruit an index:

```
acai      :  0
apple     :  1
apricot   :  2
avocado   :  3
... (up to 32 fruits total) ...
```

So, if the "zeroeth" bit in `I` is set to 0, then the set of fruit that `I` represents does not contain acai. Conversely, if the zeroeth bit in `I` is set to `1`, then the set of fruit that `I` represents does contain acai.

Or, considered another way, suppose you have the set containing only acai:
```
{acai}
```

This set is represented by `000...0001`, i.e., `I=1`.

Or, the set

```
{acai, apricot}
```
is represented by `000...0101`, i.e., `I=5`. Here, note that the "second" least significant bit (counting from zero) is also set to 1, since "apricot" is the second item in the ordered list of fruit.

For this part of the lab, you are asked to implement the following functions in `set.c`:

* `int part1_add_element(int v)`: This function adds an element with index `v` to our set `I`. 
* `int part1_remove_element(int v)`: This function removes an element with index `v` from our set `I`.
* `int part1_contains_element(int v)`: This function checks if an element with index `v` is contained in our set `I`.

You'll need to use the bitwise operators and shifts to accomplish these tasks.

You can (and should!) modify `main.c` to write test cases for your code.

Compile your code with
```
$ gcc main.c set.c -o set
```

## Part 2: Extending the bitset to an `unsigned int[]` array.

We can extend the idea from part 1 to create bitsets of arbitrary size. Instead of using a single `unsigned int`, we can use an array of them, instead.

For this part, we'll represent a set by an `unsigned int` *array* `J` with length `N`. Just like before, each *bit*
in `J` represents a unique element, and if a certain element is contained in our set, then the bit in `J` corresponding to that element is turned to 1, otherwise
0. 

But there's more than one `unsigned int`, now, so we need to decide how to order them. We'll order the bits in `J` by counting from `J[0]` to `J[N-1]`, and for each `unsigned int` from the least significant bit to the most. Consider the following example, extended from the previous example:

```
acai      :  0
apple     :  1
apricot   :  2
avocado   :  3
...
grape     : 24
...
pineapple : 51
...
tangerine : 66
...
```

Remember we represent each fruit by 1 bit, starting from the least significant bit to the most. The bit is 1 if the fruit is in our set, 0 if not. Then the set 

```
{acai}
```
is represented by `000...0001`, i.e., `J[0]=1` -- all other elements of `J` are zero.

And, just like before, the set

```
{acai, apricot}
```
is represented by `000...0101`, i.e., `J[0]=5` and all other elements of `J` are zero.

But, each element of `J` can keep track of 32 fruits, because there are 32 bits in an
`unsigned int` on the Edlab machines. 

For the following set:

```
{pineapple}
```

The corresponding bit falls in the 51s bit of J -- but each element of J has only 32 bits! So it falls in the `52 / 32` element, `J[1]` -- truncating division tells us "how many" groups of 32 into the array we need to go.

Then we need to know, which bit in `J[1]` corresponds to the element? Well, we've already advanced to J[1], which means we're 32 bits in. You could subtract 32 from 51; but that will get clunky if you're at a higher index of J. Instead, we see that we're looking for how many bits are "left over" after our division -- in other words, we're looking for the modulus. So we'd set the bit at `51 % 32 = 19`, the nineteenth least significant bit, in  `J[1]`.

More generally, a set of fruits, for example:

```
{apple, grape, pineapple, tangerine}
```
will be represented by turning the 1st, 24th, 51st, and 66th bits in our `unsigned int` array to 1. Specifically,

* `apple` corresponds to the 1st bit of `J[0]`
* `grape` corresponds to the 24th bit of `J[0]`
* `pineapple` corresponds to the 19th bit of `J[1]`
* `tangerine` corresponds to the 2nd bit of `J[2]`

And our set `{apple, grape, pineapple, tangerine}` would be represented by an
`unsigned int` array `J` where `J[0] = 16,777,218`, `J[1] = 524,288`, `J[2] = 4`, and every other component of `J` is 0. (You can and should verify that this is the case -- maybe I made a mistake!)

For this part of the lab, you are asked to implement the following functions in `set.c`:

* `int part2_add_element(int v)`: This function adds an element with index `v`
 to our set `J`. 
* `int part2_remove_element(int v)`: This function removes an element with
 index `v` from our set `J`.
* `int part2_contains_element(int v)`: This function checks if an element with
 index `v` is contained in our set `J`.

Modify `main.c` to write test cases for your code.

Compile your code with
```
$ gcc main.c set.c -o set
```

## Part 3: Hacker's Delight

Division and modulus operators are, for various reasons you'll learn in a class like COMPSCI 335, often slower than bit shifts. You can't always replace division (or multiplication, or modulus) with bit shifts -- and in fact, you usually shouldn't, as shift behavior on signed integers might not do what you expect on negative numbers. But, when what you want is to actually shift bits around, they're a great choice. (Nerds might wish to consult the antique but still fascinating and occasionally useful [Hacker's Delight](https://en.wikipedia.org/wiki/Hacker's_Delight) for more of this sort of thing.)

And, it turns out, for this lab, we're only using division and modulus for, essentially, that purpose -- we're trying to figure out what position a bit needs to go into, and we're operating on unsigned integers.

So, how can we divide by 32? It's the same as right shifting by five places (2 to the power 5 is 32; each digit we shift left is equivalent, for unsigned integers doing a logical shift, to division by 2). Recall our example of `pineapple`, which is the 51st item. We can right-shift 51 by 5 (`51 >> 5`) to divide by 32.

What about modulus, equivalent in this case to the remainder of the division? The remainder is what's "left over" after division -- it's the five bits that we "got rid of" when we shifted right by 5. Can we keep these five bits and "get rid of" the rest of the bits? Yes! There at least two ways.

If you know the number of bits you want to keep, you could mask. So, for example, if you want to keep the five least significant bits, you can bitwise-and (`&`) with the appropriate number. Here, it's 31 (which is, in binary, `000....011111`). So you could compute this as `51 & 31`.

Or, you could do it using shifts, again. Not in one bit shift, but in two.

First, we'll shift left the bits we want to get rid of -- how many? There are 32 bits total and we want to keep 5, so we'll shift left by 27.

```
51 << 27
```

Try printing the bits to see what happened.

This "gets rid of" the 27 most-significant bits by moving everything 27 places to the left. But, we also need to move those five bits we're keeping back to where they belong. Let's do it all in one expression:

```
((unsigned int)(51 << 27)) >> 27
```

(Why do we cast to `unsigned int`? Because we're tedious pedants, which you have to be if you're a C programmer! And because in your code, the argument is likely to be a regular, signed `int`, and the subsequent right shift on an `int` would be arithmetic, not logical, perhaps leading to very unexpected behavior.)

Again, try printing the bits.

For this part of the lab, modify your existing code for parts 1 and 2 to use only bit shifts to correctly implement the bitset, and make sure they still work using your test cases in `main()`!


## When you're done

Regardless of how far you got -- and we don't expect everyone to get to the end of part 3! --  submit your completed `set.c` on Gradescope. Do not modify`set.h`, and do not submit `set.h` or `main.h` -- we want only your `set.c` file.

If you work in a group, remember to add your group members to the submission in the Gradescope web interface!
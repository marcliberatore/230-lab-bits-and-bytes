# COMPSCI 230 Spring 2021
# Set with Bit Vectors

In this lab we will implement a set, represented by an `unsigned int` array.

To start working on this lab you must be logged in to the Edlab and in your
`cs230` directory. From this directory run the command:

```
$ git clone https://github.com/umass-cs-230/230-lab-bits-and-bytes
```

We represent a set by an `unsigned int` array `J` with length `N`. Each *bit*
in `J` represents a unique element. If a certain element is contained in our
set, then the bit in `J` corresponding to that element is turned to 1, otherwise
0. We order the bits in `J` by counting from `J[0]` to `J[N-1]`, and for each
`unsigned int` from the least significant bit to the most. Consider the
following example.

Suppose we have a collection of fruits. One way to represent them is to order
them alphabetically and assign each fruit  an index:

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

Remember we represent each fruit by 1 bit, starting from the least significant
bit to the most. The bit is 1 if the fruit is in our set, 0 if not. Then the set 

```
{acai}
```
is represented by `000...0001`, i.e., `J[0]=1`.

The set

```
{acai, apricot}
```
is represented by `000...0101`, i.e., `J[0]=5`.

Each component of `J` could keep track of 32 fruits, because there are 32 bits in an
`unsigned int`. For the following set

```
{pineapple}
```
The corresponding bit falls into the `(51 >> 5)`th element of `J`, which is
`J[1]`. (Right shifting by 5 is equivalent to dividing by 32.) The expression
`((unsigned int)(51 << 27)) >> 27` will tell us which bit in `J[1]` corresponds
to `pineapple`. (Why is this?) 

More generally, a set of fruits, e.g.,

```
{apple, grape, pineapple, tangerine}
```
will be represented by turning the 1st, 24th, 51st, and 66th bits in our `unsigned
int` array to 1. Specifically,

* `apple` corresponds to the 1st bit of `J[0]`
* `grape` corresponds to the 24th bit of `J[0]`
* `pineapple` corresponds to the 19th bit of `J[1]`
* `tangerine` corresponds to the 2nd bit of `J[2]`

And our set `{apple, grape, pineapple, tangerine}` would be represented by an
`unsigned int` array `J` where `J[0] = 16,777,218`, `J[1] = 524,288`, `J[2] =
4`, and every other component of `J` is 0. (You should calculate and verify that
this is the case.)

For this lab, you are asked to implement the following functions in `set.c`:

* `int add_element(int v)`: This function adds an element with index `v`
 to our set `J`. 
* `int remove_element(int v)`: This function removes an element with
 index `v` from our set `J`.
* `int contains_element(int v)`: This function checks if an element with
 index `v` is contained in our set `J`.

You are only allowed to use bitwise operators `&`, `|`, `^`, `~`, `<<`, `>>`, as
well as `+`, `-`, `<`, `>`. (You may not need all of them.) Arithmetic operators `/`,
`%`, and  `*` are not allowed.

Modify `main.c` to write test cases for your code.

Compile your code with
```
$ gcc main.c set.c -o set
```

Submit your completed `set.c` on Gradescope.

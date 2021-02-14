# COMPSCI 230 Spring 2021
# Set with Bit Vectors

In this lab we will implement a set, represented by an `unsigned int` array.

To start working on this lab you must be logged in to the Edlab and in your
`cs230` directory. From this directory run the command:

```
$ git clone https://github.com/umass-cs-230/230-lab-bits-and-bytes
```

We represent a set by an `unsigned int[]` `J` with length `N`. Each *bit* in `J`
represents a unique element. If a certain element is contained in our set, then
the bit in `J` corresponding to that element is turned to 1, otherwise 0. We
order the bits in `J` by counting from `J[0]` to `J[N-1]`, and for each
`unsigned int` from the least significant bit to the most. Consider the
following example.

Suppose we have a collection of fruits, ordered alphabetically: `acai`, `apple`,
`banana`, `cherry`, `date`, etc. Furthermore, each fruit is assigned an index:

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
```

Then a set of fruits, e.g.,

```
{apple, grape, pineapple}
```
will be represented by turning the 1st, 24th, and 51st bits in our `unsigned
int` array to 1. Specifically,

* `apple` corresponds to the 1st bit of `J[0]`
* `grape` corresponds to the 24th bit of `J[0]`
* `pineapple` corresponds to the 19th bit of `J[1]`

And our set `{apple, grape, pineapple}` would be represented by `J` where `J[0]
= 16,777,218`, `J[1] = 524,288`, and every other component of `J` is 0. (You
should calculate and verify that this is the case.)

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

Compile your code with
```
$ gcc main.c set.c -o set
```

Submit your completed `set.c` on Gradescope.

<h3 align="center">42 São Paulo - ft_printf</h3>

<div align="center">

![42 São Paulo](https://img.shields.io/badge/42-SP-1E2952)
![License](https://img.shields.io/github/license/librity/ft_printf?color=yellow)
![Code size in bytes](https://img.shields.io/github/languages/code-size/librity/ft_printf?color=blue)
![Lines of code](https://img.shields.io/tokei/lines/github/librity/ft_printf?color=blueviolet)
![Top language](https://img.shields.io/github/languages/top/librity/ft_printf?color=ff69b4)
![Last commit](https://img.shields.io/github/last-commit/librity/ft_printf?color=orange)

</div>

<div align="center">

[![Norminette v3](https://github.com/librity/ft_printf/actions/workflows/norminette_v3.yml/badge.svg)](https://github.com/librity/ft_printf/actions/workflows/norminette_v3.yml)
[![Build](https://github.com/librity/ft_printf/actions/workflows/build.yml/badge.svg)](https://github.com/librity/ft_printf/actions/workflows/build.yml)
[![FT_PRINTF_TEST](https://github.com/librity/ft_printf/actions/workflows/FT_PRINTF_TEST.yml/badge.svg)](https://github.com/librity/ft_printf/actions/workflows/FT_PRINTF_TEST.yml)
[![42TESTERS-PRINTF](https://github.com/librity/ft_printf/actions/workflows/42TESTERS-PRINTF.yml/badge.svg)](https://github.com/librity/ft_printf/actions/workflows/42TESTERS-PRINTF.yml)
[![PFT_2019](https://github.com/librity/ft_printf/actions/workflows/PFT_2019.yml/badge.svg)](https://github.com/librity/ft_printf/actions/workflows/PFT_2019.yml)

</div>

<p align="center"> A partial implementation of printf in pure C.
    <br>
</p>

---

## 📜 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Testers](#testers)
- [Github Actions](#github_actions)
- [42 São Paulo](#ft_sp)

## 🧐 About <a name = "about"></a>

This is the third project I did at 42 São Paulo:
an implementation of the famous `printf` function from scratch.

It was a big project and my first milestone at 42:
I felt properly challenged and out of my comfort zone throughout most of it.
It taught me how to organize code effectively in C,
and to separate responsibilities without resorting to
Classes and Objects (which is what I'm used to).

I managed to do it without using a single `malloc` or `free`,
but with pointers to stack structs that I pass around to each handler.
There's an isolated struct, handler, and formatter for each conversion.

The only thing that conversion "modules" share are
the flag parser and pure utility functions.
I did it this way so I didn't need to worry about breaking the formatting
of other conversions as I tinkered with the rules.

This was a really good decision since there are many formatting exceptions
and flag combinations that vary from conversion to conversion,
and it sure saved me some headaches.

## 🏁 Getting Started <a name = "getting_started"></a>

### ⚙️ Prerequisites

All you need is a shell and a C compiler like `gcc` or `clang`.

### 🖥️ Installing

To compile the entire thing just clone the repo and run `make`:

```bash
$ git clone https://github.com/librity/ft_printf.git
$ cd ft_printf
$ make
```

This will generate a `ft_printf.a` archive, which you can compile with
any of the example files:

```bash
$ cp examples/example_1.c example.c
$ gcc -g -I ./includes example.c ft_printf.a
$ ./a.out
```

## 🎈 Usage <a name="usage"></a>

You can call `ft_printf` as you would call your system's `printf` function:

```c
ft_printf("'%-10s'\n", "Hello, world!");
```

It handles most conversions:

- Percent `char`: `%%`
- Unsigned `char`: `%c`
- Signed decimal `int`: `%i` or `%d`
- Null-terminated `char *`: `%s`
- Unsigned decimal `int`: `%u`
- Uppercase hexadecimal `unsigned int`: `%X`
- Lowercase hexadecimal `unsigned int`: `%x`
- Pointer/hexadecimal memory address `unsigned long`: `%p`
- `float` and `double`: `%f`
- `long double`: `%Lf`

And also handles almost all the flags:

- Zero padding `0`
- Let-justified `-`
- Minimum field width
- Precision `.`
- Wildcard arguments `*`

Conversions and flags must respect the format:
`%[0 and/or -][width][.number]conversion`

Unfortunately there's no rigorous documentation or standard for this function,
and a lot of its behavior is implementation-specific.
There are many corner-cases that need to be ironed out by trial and error.
Since this is a 42 project, I replicated the behavior of Apple's `printf`.

[This](https://www.cplusplus.com/reference/cstdio/printf/)
is best source I could find on the project,
and should be enough to get you started.

## ✅ Testers <a name = "testers"></a>

Github Actions by [@wblech](https://github.com/wblech/42_github_actions)

- https://github.com/cclaude42/PFT_2019
- https://github.com/Mazoise/42TESTERS-PRINTF
- https://github.com/cacharle/ft_printf_test

## 🐙 Github Actions <a name = "github_actions"></a>

Norminette v3 github action
based on [@AdrianWR](https://github.com/AdrianWR)'s
[implementation](https://github.com/AdrianWR/libft/blob/master/.github/workflows/norminette.yaml).

## 🛸 42 São Paulo <a name = "ft_sp"></a>

Part of the larger [42 Network](https://www.42.fr/42-network/),
[42 São Paulo](https://www.42sp.org.br/) is a software engineering school
that offers a healthy alternative to traditional education:

- It doesn't have any teachers and classes.
- Students learn by cooperating
  and correcting each other's work (peer-to-peer learning).
- Its focus is as much on social skills as it is on technical skills.
- It's completely free to anyone that passes its selection process -
  [**The Piscine**](https://42.fr/en/admissions/42-piscine/)

It's an amazing school, and I'm grateful for the opportunity.

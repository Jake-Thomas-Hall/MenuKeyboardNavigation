# C++ Menu System with keyboard navigation

A quick project to see if I can make an object oriented menu system that is expandable and navigable via keyboard inputs.

There is *probably* some poor coding here, which I apologise for in advance to anyone reading this who *is* actually a professional C++ developer and knows better. Please feel free to make a PR and correct any horriffic code mistakes I'm making, I would appreciate it!

Some of the classes used in this project were originally created in an earlier project, which you can see here (although, I woudln't recommend it as it's kind of a mess):

https://github.com/Diedinium/Payroll-Budget-Calculator

## Example

![](https://media3.giphy.com/media/KNzbc3XTZjcTHoy6fe/giphy.gif)

## Compatibility notes

Built with Visual Studio, and relies on `windows.h` so is not cross platform - sorry 🙁

If you want to try it out on your own system, I recommend using VS - although I guess there is nothing stopping you from converting this to a cmake project etc if you wanted to ¯\\\_(ツ)\_/¯

Still, the reliance on `windows.h` here would prevent it working on Linux etc, plus I'm well aware that the `system("cls")` calls I'm making are not a good idea either...

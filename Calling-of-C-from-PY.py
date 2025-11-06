from ctypes import *;
# modeule ha yeh 
c_file_path = r"D:\100 days\31th\customlib1.dll"
c_fun=CDLL(c_file_path)
a=c_fun.lcm(4,6)
b=c_fun.fact(5)
print("The Lcm is : \n",a)
print("The Factorial is : \n",b)

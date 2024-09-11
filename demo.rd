#input<2> means it takes in 2 inputs which is an array of bool
#->2 means it returns 2 output
module half_adder(input<2>)->2{
    #I want to give feature so that the user can render the circuit so for that u can set a few properties that can be displayed.It is optional tho
    @property={
        "name":"Half Adder",
        "input":["A","B"],
        "output":["Carry","Sum"]
    }
    A=input[0]
    B=input[1]
    A_and_B=A&B
    carry=A_and_B
    not_A_and_B=!A_and_B
    sum=(!(A&not_A_and_B))&(!(B&not_A_and_B))
    return [carry,sum]
}
module full_adder(input<3>)->2{
    A=input[0]
    B=input[1]
    C=input[2]

    h1=half_adder(A,B)
    h2=half_adder(h1[1],C)

    sum=h2[1]

    carry=h2[0]|h1[0]

    return [carry,sum]
}
#module are basic building block of the circuit
#They are combined to create bigger building block which I am calling functions
#The diffrence is that functions can take in multiple input<n> as argument whereas modules take only 0 or 1 such argument
#{n} acts as a compile time macro
fn n_bit_adder{n}(num1<n>,num2<n>)->n{
    #Note:-If else and for loop like statement only work for constexpr like n i.e it works like a macro. Not on num1,num2 etc because in digital circuit u dont have if else statement
    $if n==0{
        $compile_error("n>=1")
    }
    output:n #Defines a n bit long list of bool
    carry=0
    # $ means it is a compile time macro so the for loop is unrolled at compile time if n is small enough or it is executed at run time
    $for i in 0..n{
        a=full_adder(num1[i],num1[i],carry)
        carry=a[0]
        output[i]=a[1]
    }
    return output
}

import module

fn demo(num<2>)->2{
    return module::gate(num)
}

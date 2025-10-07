// Get necessary elements.
const display = document.querySelector('.calc-display');
const acButton = document.querySelector('.btn-ac');
const plusButton = document.querySelector('.btn-plus');
const minusButton = document.querySelector('.btn-minus');
const multiplyButton = document.querySelector('.btn-multiply');
const divisionButton = document.querySelector('.btn-division');
const equalButton = document.querySelector('.btn-equal');
const Button1 = document.querySelector('.btn-1');
const Button2 = document.querySelector('.btn-2');
const Button3 = document.querySelector('.btn-3');
const Button4 = document.querySelector('.btn-4');
const Button5 = document.querySelector('.btn-5');
const Button6 = document.querySelector('.btn-6');
const Button7 = document.querySelector('.btn-7');
const Button8 = document.querySelector('.btn-8');
const Button9 = document.querySelector('.btn-9');
const Button0 = document.querySelector('.btn-0');



let currentDisplay = '';
Button0.addEventListener('click', () => {
    display.value += '0'
})
Button1.addEventListener('click', () => {
    display.value += '1'
})
Button2.addEventListener('click', () => {
    display.value += '2'
})
Button3.addEventListener('click', () => {
    display.value += '3'
})
Button4.addEventListener('click', () => {
    display.value += '4'
})
Button5.addEventListener('click', () => {
    display.value += '5'
})
Button6.addEventListener('click', () => {
    display.value += '6'
})
Button7.addEventListener('click', () => {
    display.value += '7'
})
Button8.addEventListener('click', () => {
    display.value += '8'
})
Button9.addEventListener('click', () => {
    display.value += '9'
})

plusButton.addEventListener('click', () => {
    display.value += '+';
});
minusButton.addEventListener('click', () => {
    display.value += '-';
});

multiplyButton.addEventListener('click', () => {
    display.value += '*';
});

divisionButton.addEventListener('click', () => {
    display.value += '/';
});


acButton.addEventListener('click', () => {
    currentDisplay = '';
    display.value = currentDisplay;
});

display.addEventListener('keydown', (ev) => {
    ev.preventDefault();
});

equalButton.addEventListener('click', () => {
    const command = display.value.split(/[ \+\-\*\/]/);
    const num1 = parseInt(command[0]);
    const num2 = parseInt(command.pop());
    
    if (display.value.includes('+')) {
        display.value = `${display.value} = ${num1 + num2}`;
    }
    if (display.value.includes('-')) {
        display.value = `${display.value} = ${num1 - num2}`;
    }
    if (display.value.includes('*')) {
        display.value = `${display.value} = ${num1 * num2}`;
    }
    if (display.value.includes('/')) {
        display.value = `${display.value} = ${num1 / num2}`;
    }
});

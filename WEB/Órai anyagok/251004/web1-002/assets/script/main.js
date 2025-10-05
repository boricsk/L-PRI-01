// Get necessary elements.
const display = document.querySelector('.calc-display');
const acButton = document.querySelector('.btn-ac');
const plusButton = document.querySelector('.btn-plus');
const minusButton = document.querySelector('.btn-minus');
const multiplyButton = document.querySelector('.btn-multiply');
const divisionButton = document.querySelector('.btn-division');
const equalButton = document.querySelector('.btn-equal');

let currentDisplay = '';
acButton.addEventListener('click', () => {
    currentDisplay = '';
    display.value = currentDisplay;
});

display.addEventListener('keydown', (ev) => {
    if (/[^0-9\+\-\*\/ ]/.test(ev.key)) {
        ev.preventDefault();
    }
});

equalButton.addEventListener('click', () => {
    const command = display.value.split(/[ \+\-\*\/]/);
    const num1 = parseInt(command[0]);
    const num2 = parseInt(command.pop());
    if (display.value.includes('+')) {
        display.value = `${display.value} = ${num1 + num2}`;
    }
});

const { Coordinate } = require('bindings')('main');

const coordinate = new Coordinate(1, 2);
const coordinate2 = new Coordinate(2, 3);

console.log(coordinate.dot(coordinate2)); // 8

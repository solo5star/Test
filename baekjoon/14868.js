var input = require('fs').readFileSync('/dev/stdin').toString().trim();

console.log(solution(input));

function coordHash(x, y){
	return 2000 * x + y;
}

function solution(input){
	var lines = input.split("\n");

	var worldSize = parseInt(lines[0].split(" ")[0]);
	var cultureCount = parseInt(lines[0].split(" ")[1]);
	lines.shift();

	var cultureCoords = lines.map(function(rawCoord){
		return rawCoord.split(" ").map(function(coord){
			return parseInt(coord);
		});
	});

	var mergeCompleteCultures = {0: true};
	var world = {};

	var needUpdate = {};
	var needSpread = {};

	for(var cultureId in cultureCoords){
		var [x, y] = cultureCoords[cultureId];
		world[coordHash(x, y)] = [ x, y, cultureId ];

		needUpdate[coordHash(x, y)] = [ x, y, cultureId];
	}

	var yearElappsed = 0;
	while(true){
		for(var updateCoord of Object.values(needUpdate)){
			var [ux, uy, cultureId] = updateCoord;
			var adjacents = [
				[ux - 1, uy],
				[ux, uy - 1],
				[ux + 1, uy],
				[ux, uy + 1]
			];

			var validated = [];
			for(var i in adjacents){
				var [ax, ay] = adjacents[i];
				if(ax < 1 || ax > worldSize || ay < 1 || ay > worldSize){
				}else{
					validated.push(adjacents[i]);
				}
			}
			adjacents = validated;

			for(adjacentCoord of adjacents){
				var [ax, ay] = adjacentCoord;
				if(world[coordHash(ax, ay)] === undefined){
					needSpread[coordHash(ax, ay)] = [ax, ay, cultureId];
				}else{
					var cultureInfo2 = world[coordHash(ax, ay)];
					var cultureId2 = cultureInfo2[2];
					if(cultureId2 != cultureId){
						mergeCompleteCultures[cultureId] = true;
						mergeCompleteCultures[cultureId2] = true;
						if(Object.keys(mergeCompleteCultures).length == cultureCount){
							return yearElappsed;
						}
					}
				}
			}
		}
		Object.values(needSpread).forEach(function(spreadCoord){
			var [sx, sy, cultureId] = spreadCoord;
			world[coordHash(sx, sy)] = [sx, sy, cultureId];
		});

		needUpdate = needSpread;
		needSpread = [];

		yearElappsed++;
	}
}
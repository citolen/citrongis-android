console.log('interface script');

console.log('[RESULT]', require('testinside'));

this.myvar = 'CitronGIS App';

this.myfunc = function () {
    console.log('my click');
};

this.coffee_result = this.CoffeeScript.run('console.log "Hello from coffee-script in citronGIS bitch!"\n\
times = (a, b) -> a * b\n\
return times(2, 5)');

var self = this;
Function(self.CoffeeScript.compile(require('html/coffee/func.coffee'))).call(self);

console.log(this);

var radarChartData = {
		labels: ["Eating", "Drinking", "Sleeping", "Designing", "Coding", "Cycling", "Running"],
		datasets: [
			{
				label: "My First dataset",
				fillColor: "rgba(220,220,220,0.2)",
				strokeColor: "rgba(220,220,220,1)",
				pointColor: "rgba(220,220,220,1)",
				pointStrokeColor: "#fff",
				pointHighlightFill: "#fff",
				pointHighlightStroke: "rgba(220,220,220,1)",
				data: [65,59,90,81,56,55,40]
			},
			{
				label: "My Second dataset",
				fillColor: "rgba(151,187,205,0.2)",
				strokeColor: "rgba(151,187,205,1)",
				pointColor: "rgba(151,187,205,1)",
				pointStrokeColor: "#fff",
				pointHighlightFill: "#fff",
				pointHighlightStroke: "rgba(151,187,205,1)",
				data: [28,48,40,19,96,27,100]
			}
		]
	};


this.UI.on('loaded', function (e) {
    Function(self.CoffeeScript.compile(require('html/coffee/test.coffee'))).call(self);
    var ctx = document.getElementById("canvas").getContext("2d");
    window.myRadar = new self.Chart(ctx).Radar(radarChartData, {
			responsive: false
		});
});

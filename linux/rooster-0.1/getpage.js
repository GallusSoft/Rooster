var page = require('webpage').create();
var origin = '';
var dest = '';

var args = require('system').args;
args.forEach(function(arg, i) {

    if(i == 1)
    {
       origin = arg;
    }

    if(i == 2)
    {
       dest = arg;
    }

});

page.open(encodeURI('https://maps.google.com/maps?saddr=' + origin + '&daddr=' + dest), function (status) {

	if (status !== 'success') {
		console.log('Unable to access network');
		phantom.exit();
        } else {

		// dir_altroutes_body returns all routes, with altroute_[numberincremetingfrom0] as the id of each route
		// update later to count routes. for now, we're just using Google's first choice.

		var routes = page.evaluate(function() {
		return document.getElementById('altroute_0').getElementsByClassName('altroute-rcol altroute-aux')[0].getElementsByTagName('span')[0].textContent;
		});




		if (routes == undefined) {

			var notraffic = page.evaluate(function() {
			return document.getElementById('altroute_0').getElementsByClassName('altroute-rcol altroute-info')[0].getElementsByTagName('span')[1].textContent;
			});

		console.log(notraffic);

		} else {



		if (routes == ' No traffic information ') {

			var notraffic = page.evaluate(function() {
			return document.getElementById('altroute_0').getElementsByClassName('altroute-rcol altroute-info')[0].getElementsByTagName('span')[1].textContent;
			});

			if (notraffic == undefined) {
	
				console.log('null');

			} else {

				console.log(notraffic);

			}

		} else {
			console.log(routes.substring(21,36));
		}
	}
	phantom.exit();
}});

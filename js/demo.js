//jQuery plugin responds to cursor input//

$(document).ready(function() {
  $('#particles').particleground({
    dotColor: '#7D5D4E',
    lineColor: '#7D5D4E',
    particleRadius: 7, // Dot size
    lineWidth: .5,
    curvedLines: false,
    proximity: 100,
	density: '10000'
  });
  $('.intro').css({
    'margin-top': -($('.intro').height() / 2)
  });
});

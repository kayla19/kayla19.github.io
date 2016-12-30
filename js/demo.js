//jQuery plugin responds to cursor input//

$(document).ready(function() {
  $('#particles').particleground({
    dotColor: '#ffffff',
    lineColor: '#ffffff',
    particleRadius: 3, // Dot size
    lineWidth: .125,
    curvedLines: false,
    proximity: 100,
	density: '6500'
  });
  $('.intro').css({
    'margin-top': -($('.intro').height() / 2)
  });
});

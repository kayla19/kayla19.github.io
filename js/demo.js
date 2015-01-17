//jQuery plugin responds to cursor input//

$(document).ready(function() {
  $('#particles').particleground({
    dotColor: '#008C9E',
    lineColor: '#00B4CC',
	density: '8000'
  });
  $('.intro').css({
    'margin-top': -($('.intro').height() / 2)
  });
});
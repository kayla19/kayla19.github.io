//jQuery plugin responds to cursor input//

$(document).ready(function() {
  $('#particles').particleground({
    dotColor: '#BFCDB4',
    lineColor: '#BFCDB4',
	density: '6000'
  });
  $('.intro').css({
    'margin-top': -($('.intro').height() / 2)
  });
});

//jQuery plugin responds to cursor input//

$(document).ready(function() {
  $('#particles').particleground({
    dotColor: '##7D5D4E',
    lineColor: '#7D5D4E',
	density: '2000'
  });
  $('.intro').css({
    'margin-top': -($('.intro').height() / 2)
  });
});

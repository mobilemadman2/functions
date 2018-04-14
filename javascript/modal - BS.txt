//control modal show or hide
$("#alarmRingModal").modal("hide");

//check if modal is shown
$('#report').hasClass('in'); //return true if shown

//force modal to removed
$('body').removeClass('modal-open');
$('.modal-backdrop').remove();
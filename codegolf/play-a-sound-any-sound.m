%{

Your program has to make the computer produce a sound, any sound.

Shortest code wins, not sooner than 10 days after the first valid answer. If there is a tie, the one submitted sooner, wins.

The program should run on a reasonable, not too uncommon personal computer.
Opening a pop-up, message box, etc. (for example, on a web page) does not count, as they might or might not produce a sound, depending on a lot of settings.
Just entering a wrong command or invalid character on a console and receiving a warning beep does not count, just as the compiler/interpreter/OS beeping on an error or crash does not count either. Your code must be a valid program.

%}

% https://www.mathworks.com/matlabcentral/answers/48717-create-a-piece-of-music-using-matlab
samplerate = 48000
notecreate = @(frequency, duration) sin(2*pi*[1:duration]/samplerate * (440*2.^((frequency-1)/12)));
notename = {'A' 'A#' 'B' 'C' 'C#' 'D' 'D#' 'E' 'F' 'F#' 'G' 'G#'};

song = {'A' 'A' 'E' 'E' 'F#' 'F#' 'E' 'E' 'D' 'D' 'C#' 'C#' 'B' 'B' 'A' 'A'};
for i = 1:length(song)
	index = strcmp(song(i), notename);
	songindex(i) = find(index);
end

duration = 0.3*samplerate;
songnote = [];
for i = 1:length(songindex)
	songnote = [songnote; [notecreate(songindex(i), duration)]'];
end

while true
	soundsc(songnote, samplerate, 24)
end

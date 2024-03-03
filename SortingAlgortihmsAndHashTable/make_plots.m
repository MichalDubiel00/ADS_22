clear;clc;close all;

 fid=fopen("quicksort.txt");
 data=textscan(fid,"%d %f");
 fclose(fid);
 x=data{1};
 quicksort_y=data{2};

 fid=fopen("hybridquicksort.txt");
 data=textscan(fid,"%d %f");
 fclose(fid);
 x=data{1};
 hybridquicksort_y=data{2};

 fid=fopen("mergesort.txt");
 data=textscan(fid,"%d %f");
 fclose(fid);
 mergesort_y=data{2};

  fid=fopen("natmergesort.txt");
 data=textscan(fid,"%d %f");
 fclose(fid);
 natmergesort_y=data{2};

 fid=fopen("heapsort.txt");
 data=textscan(fid,"%d %f");
 fclose(fid);
 heapsort_y=data{2};

 

 fid=fopen("shellsort_2n.txt");
 data=textscan(fid,"%d %f");
 fclose(fid);
 shellsort_2n_y=data{2};

  fid=fopen("shellsort_3n.txt");
 data=textscan(fid,"%d %f");
 fclose(fid);
 shellsort_3n_y=data{2};


   figure;
   title( "sorting algorithms" );
   xlabel( "n [-]" );
   ylabel(" t [s]" );
   hold on;
   plot(x,quicksort_y);
   plot(x,hybridquicksort_y);
   plot(x,mergesort_y);
   plot(x,natmergesort_y);
   plot(x,heapsort_y);
   plot(x,shellsort_2n_y);
   plot(x,shellsort_3n_y);

  legend( "quicksort","hybridquicksort" ,"mergesort","natmergesort","heapsort","shellsort_2n","shellsort_3n","Location","northwest");
  hold off;
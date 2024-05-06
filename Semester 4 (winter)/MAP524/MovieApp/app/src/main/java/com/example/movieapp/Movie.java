package com.example.movieapp;
import android.os.Parcel;
import android.os.Parcelable;

public class Movie implements Parcelable {
    private String title;
    private int year;
    private String imdbID;
    private String type;
    private String posterUrl;

    public Movie(String title, int year, String imdbID, String type, String posterUrl) {
        this.title = title;
        this.year = year;
        this.imdbID = imdbID;
        this.type = type;
        this.posterUrl = posterUrl;
    }

    protected Movie(Parcel in) {
        title = in.readString();
        year = in.readInt();
        imdbID = in.readString();
        type = in.readString();
        posterUrl = in.readString();
    }

    public static final Creator<Movie> CREATOR = new Creator<Movie>() {
        @Override
        public Movie createFromParcel(Parcel in) {
            return new Movie(in);
        }

        @Override
        public Movie[] newArray(int size) {
            return new Movie[size];
        }
    };

    public String getTitle() {
        return title;
    }

    public int getYear() {
        return year;
    }

    public String getImdbID() {
        return imdbID;
    }

    public String getType() {
        return type;
    }

    public String getPosterUrl() {
        return posterUrl;
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(title);
        dest.writeInt(year);
        dest.writeString(imdbID);
        dest.writeString(type);
        dest.writeString(posterUrl);
    }
}

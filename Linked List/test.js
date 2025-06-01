const likeSchema = mongoose.Schema(
  { likesCount: integer },
  { timestamps: true }
);
const Like = mongoose.model("Like", likeSchema);

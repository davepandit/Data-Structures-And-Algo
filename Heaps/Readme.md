#### 🔍 Why Not Only Use heapifyDown?

When deleting an element from a heap (not just the root), we replace it with the last element and then need to restore the heap property. Whether we use heapifyDown, heapifyUp, or both depends on where the replacement element came from and how it compares to its new parent and children.

#### 🧠 Here's the key idea:

If the replacement value is larger than its parent, it violates the max-heap condition upward ⇒ needs heapifyUp.

If the replacement value is smaller than one of its children, it violates the max-heap condition downward ⇒ needs heapifyDown.

#### 📌 So, why can't we use only heapifyDown?

```Let’s consider this example:```

Max-Heap:

         90
       /    \
     80      70
    /  \    /  \
    60  50 65  55

```Array: [90, 80, 70, 60, 50, 65, 55]```

Now suppose we delete the node at index 1 (value 80):

Replace it with the last value 55.

New heap: [90, 55, 70, 60, 50, 65]

Now 55 is less than its child 60, so heapifyDown works.

#### ✅ Perfect! In this case, heapifyDown is sufficient.

But now suppose the last value was 85 instead:

Replace 80 with 85 ⇒ [90, 85, 70, 60, 50, 65]

Now 85 is **greater than its parent 90` ⇒ no upward violation.

But also greater than both children 60 and 50.

#### ➡️ So no need to heapifyDown either.

So far so good.

#### 💣 But now imagine the last value is 95.
Replace 80 with 95 ⇒ [90, 95, 70, 60, 50, 65]

Now 95 > 90, violating the heap property upward.

heapifyDown won't do anything here because it checks children only — but 95 is already bigger than them.

#### 🚫 So if you only call heapifyDown, the heap stays invalid!

#### ✅ Conclusion
heapifyDown fixes violations downward.

But if the new value is greater than its parent, only heapifyUp can fix it.

That’s why we need to try both:

```
heapifyDown(...);

heapifyUp(...);
```

(Or if you're optimizing, you can compare the new value with its parent to decide which one to call.)
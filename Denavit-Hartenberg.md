Denavit-Hartenberg parameters define the motion of actuators connected by rigid links
a series of joints
this is useful for xxx calculations

the process begins by defining the z-axis, alo


Denavit-Hartenberg Reference Frame Layout
Denavit-Hartenberg 参考坐标系的布局
Produced by Ethan Tira-Thompson
由Ethan Tira-Thompson制作
D-H parameters define the motion of actuators connected by rigid links.
D-H参数定义了刚性连杆执行器的运动
                   Base frame
                   基本坐标系
                   (generically,”previous joint”)
                   （一般而言，“早先的联合”）
Z axis points along axis of rotation.
Z轴的指向沿着旋转轴
(or axis of translation for a prismatic joint)
（或移动副轴）
X axis for base frame is a free choice; constrained for subsequent joints.
基本坐标系的x轴的选择是自由的，但限制了后续的连杆
Y axis is now constrained to complete right-handed coordinate frame.
Y轴，基于右手坐标系来建立
Now, let’s add the next joint.
现在，我们加上下一个连杆
Again, the z axis is defined by the axis of actuation.
同样的，z轴的方向由执行器的旋转轴的方向决定。
D-H parameters are derived from common normal between consecutive z axes.
D-H参数来源于两个相邻z轴的公共联系
New x axis is colinear with common normal, with origin at intersection with new z.
新的x轴是两条z轴的公垂线
Notice the origin is not at the center of the actuator.
注意到，最初的x轴并不在执行器的中心
The origin may be in “open space”.
最初的z轴位置并不限定
With these joint axes, four parameters specify the joint-to-joint transformation:d,θ,γ,α.
连杆可以有许多，而我们用四个参数来共同描述这些连杆
d is the depth along the prexious joint’s z axis.
d 连续公垂线之间的偏移（书本上为b）
Θ is the angle about the previous z to align its x with the new origin.
Θ是相邻x轴之间的夹角
Γ is the distance along the rotated x axis.
Γ相邻z轴的距离（书本上为a）
Alternatively, radius of rotation about previous z.
也就是以之前的z轴为中心，之后连杆定义的x轴与z轴的交点为圆上一点，画圆弧，半径即为γ
Finally, α rotates about the new x axis to put z in its desired orientation.
最后，α表示相邻z轴间的夹角
(special case: parallel z axes)
（特殊的情况，当相邻的z轴平行时）
Parallel z axes have an infinite number of common normals.
平行z轴具有共同的法线无限多的。
Choose any convenient d——连续公垂线之间的偏移
选择任意一个方便的
Other parameters determined as before
其他参数像之前一样确定
Z already aligned(otherwise this case wouldn’t apply) α=0
Z轴已经平行，故α=0
Congratulations
祝贺
Now you know how to lay out Denavit-Hartenberg parameters!
现在你知道怎么描述D-H参数了

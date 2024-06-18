**Trees - STL, Templates, and Iterators**

עץ הוא גרף קשיר ללא מעגלים. במטלה זו מימשתי קונטיינר המייצג עץ k-ארי (עץ k-ארי הוא עץ שבו לכל קודקוד יש לכל היותר k ילדים. למשל, עץ בינארי הוא עץ 2-ארי.) גנרי שמכיל מפתחות מכל סוג (למשל מספרים, מחרוזות ומחלקות). המצב הדיפולטיבי של העץ הוא עץ בינארי (כלומר k=2). בשלב היצירה של הקונטיינר נציין את סוג המפתח ואת כמות הילדים המקסימלית של העץ. 
בבפרוייקט מימשתי את האיטרטורים הבאים:
 איטרטור Pre-Order - איטרטור הסורק את העץ בצורה הבאה: צומת נוכחית -> תת עץ שמאלי -> תת עץ ימני (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי יחזיר סריקת DFS רגילה שמתחילה מהשורש של העץ).
    איטרטור Post-Order - איטרטור הסורק את העץ בצורה הבאה: תת עץ שמאלי -> תת עץ ימני -> צומת נוכחית (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי יחזיר סריקת DFS רגילה שמתחילה מהשורש של העץ).
    איטרטור In-Order - איטרטור הסורק את העץ בצורה הבאה: תת עץ שמאלי -> צומת נוכחית -> תת עץ ימני (האיטרטור הזה עובד בצורה הזאת עבור עץ בינארי בלבד! עבור עץ כללי יחזיר סריקת DFS רגילה שמתחילה מהשורש של העץ).
    איטרטור BFS - סריקת העץ לרוחב (משמאלי לימין) (עובד על עץ כללי).
    איטרטור DFS - סריקת העץ בעזרת אלגוריתם DFS (עובד על עץ כללי).
    איטרטור Heap - הפיכת עץ בינארי לערימת מינימום(נעשה שימיש בספריית האלגוריתמים של הספריה הסטנדרטית.


במחלקת TREE ניתן למצוא אתה מתודות הבאות:

    המתודה add_root - הוספת השורש של העץ. המתודה מקבלת צומת כלשהו ושמה אותו בשורש העץ.
    המתודה add_sub_node - הוספת ילד לאב. המתודה מקבלת צומת בעץ וצומת כלשהו ויוצרת בן עבור אותו צומת.
    המתודות begin_pre_order, end_pre_order. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Pre-Order.
    המתודות begin_post_order, end_post_order. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת Post-Order.
    המתודות begin_in_order, end_in_order. המתודות מחזירות איטרטורים לצורך מעבור על העץ בשיטת In-Order.
    המתודות begin_bfs_scan, end_bfs_scan. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם BFS.
    המתודות begin_dfs_scan, end_dfs_scan. המתודות מחזירות איטרטורים לצורך מעבור על העץ בעזרת האלגוריתם DFS.
    המתודה myHeap. המתודה מקבלת איטרטורים לעץ בינארי ומחזירה איטרטורים עבור הערימה שהתקבלה.
    אופרטור פלט. הפלט נוצר בעזרת GUI ע"י שימוש בספרייה SFML. דוגמא להדפסת העץ:
![image](https://github.com/RoniHarTuv/Tree_Templates_Iterator/assets/149065885/98d9fdbb-a9aa-4d28-849d-038037b5e271)


מחלקות הפרוייקט-פירוט:
    1. חלקת Node המייצגת "קודקוד" בעץ. לכל Node יש data מטיפוס גנרי, ווקטור של ילדי הnode.
    2.מחלקת Complex המייצגת מספר מרוכב
    3. מחלקת Tree המייצגת את העץ שתואר לעיל. במחלקה זו נמצאים כל המימושים של האיטרטורים ושל אופרטור הפלט. הרעיון הכללי לביצוע איטרטור- עבור כל סוג מעבר על העץ, יצרתי פונקציית עזר אשר
    אחראית על המעבר בפועל. לכל עץ אתחלתי שדה ווקטור שמכיל את הNode שבעץ לפי סדר מסויים. פונקציות העזר מקבלות מצביע לווקטור הזה ומחזירות אותו מלא לפי סו המעבר שבוצע. כך שכל מה שנותר בעצם
    הוא לבצע איטרציה על אותו המערך- וזה יהיה מימוש האיטרטור בפועל. בצורה זו begin תמיד יצביע על תחילת המערך- ז"א על הnode הראשון , וend תמיד יצביע לסופו(כאשר הוא מצביע לnull).
    4. מחלקת Test המכילה מגוון טסטים הבודקים מקרי קצה כגון- הוספת מספר רב של קודקודים- מעבר לגבולות העץ שהוגדר, הוספת תת קודקוד לקודקוד שלא קיים, טיפול בעץ ריק וכ'ו.
    5. מחלקות התומכות את מחלקת טסט כגון doctest, testCounter  וכ'ו.


הפקודה make tree מריצה את התוכנית הראשית המדגימה 4 סוגי עצים שונים ואת המעבר עליהם.

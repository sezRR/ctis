<style>
    nav ul {
        list-style: none;
        display: flex;
        justify-content: center;
        align-items: center;
        gap: 2rem;
        background-color: whitesmoke;
        padding: 0.75rem;
        border-bottom: 1px solid gray;

        & li {
            width: 5rem;

            & a {
                text-decoration: none;
                color: black;
                text-transform: uppercase;
                display: block;
                flex: 1;

                &:hover {
                    font-weight: bold;
                }
            }
        }
    }
</style>
<nav>
    <ul>
        <li><a href="">Page 1</a></li>
        <li><a href="">Page 2</a></li>
        <li><a href="">Page 3</a></li>
    </ul>
</nav>
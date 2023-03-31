export function Item({ index, item, style }) {
    return (
        <div key={index} style={style}>
            <span>{item}</span>
        </div>
    );
}
